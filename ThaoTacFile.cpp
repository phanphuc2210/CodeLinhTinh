#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void DocFile(ifstream &filein,vector<string> &arr){
    filein.open("input.txt",ios_base::in);
    string str;
    if(!filein){
        cout << "Khong tim thay file. Vui long kiem tra lai.";
        system("pause");
        exit(0);//Đóng chương trình 
    }
    while(!filein.eof()){
            filein >> str;
            if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') ){
                arr.push_back(str);
            } 
        }
    filein.close();    
}

void Xuat(vector<string> arr){
    int size = arr.size();    
    for(int i = 0 ; i < size ; i++){
        cout << "str = " << arr[i] << endl;
    }
}

void TuCoDoDaiLonNhat(vector<string> arr){
    int max = arr[0].length();
    int size = arr.size();
    int index = 0;
    for(int i = 1 ; i < size ; i++){
        if(max <= arr[i].length()){
            max = arr[i].length();
            index = i;
        }
    }
    cout << "\nTu dai nhat la : " << arr[index] << endl;
}

void xoaTuGiongNhau(vector<string> &arr){
    int size = arr.size();
    for(int i = 0 ; i < size - 1 ; i++){
        for(int j = i + 1 ; j < size ; j++){
            if(arr[i] == arr[j]){//So sánh có phân biệt hoa thường
                //if(strcmp(strlwr((char*)arr[i].c_str()),strlwr((char*)arr[j].c_str())) == 1)
                //so sánh không phân biệt hoa thường
                arr.erase(arr.begin() + j);
                size--;
                j--;
            }
        }
    }
}

//Đảo ngược vecto sau đó bỏ vào file output.txt
void DaoNguocVaGHiFile(ofstream &fileout,vector<string> arr){
    fileout.open("output.txt",ios_base::out);
    int size = arr.size();
    for(int i = size - 1 ; i >= 0 ; i--){
        fileout << arr[i] << " ";
    }

    fileout.close();
}

int main(){
    ifstream filein;
    vector<string> arr;
    ofstream fileout;
    
    DocFile(filein,arr);
    cout << "\nFILE DOC DUOC LA : \n\n";
    Xuat(arr);

    TuCoDoDaiLonNhat(arr);

    xoaTuGiongNhau(arr);
    cout << "\nSau khi xoa cac tu giong nhau : \n\n";
    Xuat(arr);

    DaoNguocVaGHiFile(fileout,arr);

    system("pause");
    return 0;
}

