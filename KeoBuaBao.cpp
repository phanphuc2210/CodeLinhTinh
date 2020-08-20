#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

int Random(int min,int max){
    return min + rand() % (max - min + 1);
}

string hienThi(int choose){
    if(choose == 1){
        return "KEO";
    }
    else if(choose == 2){
        return "BUA";
    }
    else 
        return "BAO"; 
}

void KetQua(int luachon,int res){
    cout << "\nLua chon cua ban la : " << hienThi(luachon) << endl;
    cout << "Lua chon cua doi phuong la : " << hienThi(res) << endl;
    if(luachon == 1 && res == 3 || luachon == 2 && res == 1 || luachon == 3 && res == 2){
        cout << "\n\n\t\t====== YOU WIN ======\n";
    }
    else if(luachon == res){
        cout << "\n\n\t\t======YOU DRAW======\n";
        cout << "\t=====MOI BAN CHON LAI !!!!!=====\n";
    }
    else {
        cout << "\n\n\t\t====== YOU LOSE ======\n";
    }
}

int main(){
    int luachon;
    srand((int)time(0));
    int res = Random(1,3);
    do{
        res = Random(1,3);
        do{
            cout << "\nNhap vao lua chon (1.Keo , 2.Bua , 3.Bao) : ";
            cin >> luachon;

            if(luachon < 1 || luachon > 3){
                cout << "\n\tLua chon khong hop le . Moi nhap lai!!!\n";
            }
        }while(luachon < 1 || luachon > 3);

        KetQua(luachon,res);
        
    }while(luachon == res);
    
    system("pause");
    return 0;
}