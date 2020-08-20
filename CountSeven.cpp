#include <iostream>
using namespace std;

int countSevenVongLap(int n){
    int dem = 0;
    while(n != 0){
        int chuso = n % 10;
        n = n / 10;

        if(chuso == 7){
            dem++;
        }
    }
    return dem;
}

int countSevenDeQuy(int n){
    if(n == 0){
        return 0;
    }
    return (n % 10 == 7 ? 1 : 0) + countSevenDeQuy(n / 10);
}

int main(){
    system("cls");
    int n;
    cout << "Nhap vao so nguyen n can dem so 7 : ";
    cin >> n;

    cout << "\nSo chu so 7 co trong " << n << " la : " << countSevenDeQuy(n) << endl;

    system("pause");
    return 0;
}