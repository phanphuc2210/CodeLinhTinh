#include <iostream>
using namespace std;

void NhapMang2ChieuDong(int **p,int sodong,int socot){
    for(int i = 0 ; i < sodong ; i++){
        for(int j = 0 ; j < socot ; j++){
            cout << "a[" << i << "][" << j << "] = ";
            cin >> p[i][j];
        }
    }
}

void XuatMang2ChieuDong(int **p,int sodong,int socot){
    for(int i = 0 ; i < sodong ; i++){
        for(int j = 0 ; j < socot ; j++){
            cout << p[i][j] << "   ";
        }
        cout << "\n";
    }
}

int TongCacSoDuong(int **p,int sodong,int socot){
    int S = 0;
    for(int i = 0 ; i < sodong ; i++){
        for(int j = 0 ; j < socot ; j++){
            if(p[i][j] > 0){
                S += p[i][j];
            }
        }
    }
    return S;
}

int main(){
    int sodong , socot;
    cout << "Nhap vao so dong : ";
    cin >> sodong;
    cout << "Nhap vao so cot : ";
    cin >> socot;

    int **p = new int*[sodong];//cấp phát dòng trước rồi mới
    for(int i = 0 ; i < sodong ; i++){
        p[i] = new int[socot];//cấp phát cột
    }

    cout << "\nNhap mang dong 2 chieu :\n";
    NhapMang2ChieuDong(p,sodong,socot);

    cout << "\nMang vua nhap la : \n";
    XuatMang2ChieuDong(p,sodong,socot);

    int tong = TongCacSoDuong(p,sodong,socot);
    cout << "\nTong cac so nguyen duong trong mang la : " << tong << endl;

    //Dùng xong thì phải xóa bộ nhớ đã cấp phát động
    for(int i = 0 ; i < sodong ; i++){
        delete[] p[i];//xóa cột trước
    }
    delete[] p;//rồi mới xóa dòng

    system("pause");
    return 0;
}