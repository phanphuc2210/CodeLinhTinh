#include <iostream>
#include <string>
using namespace std;

int KiemTra(string str){
    int dauNgoac = 0;
    int n = str.length();
    for(int i = 0 ; i < n ; i++){
        if(str[i] == '('){
            dauNgoac++;
        }
        else if(str[i] == ')'){
            if(dauNgoac == 0) {
                dauNgoac = 0;//CÓ DẤU ĐÓNG NGOẶC MÀ KHÔNG CÓ DẤU MỞ NÊN sai LUÔN
            }
            else dauNgoac--;
        }
    }
    return dauNgoac;
}

int main(){
    string str = "(()())(";
    int ktra = KiemTra(str);

    if(ktra == 0) cout << "true" << endl;
    else cout << "false" << endl;

    system("pause");
    return 0;
}