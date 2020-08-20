#include <iostream>
using namespace std;

void chuyen(int n,char nguon,char trunggian,char dich){
    if(n == 1){
        cout << nguon << " --> " << dich << endl;
    }
    else {
        chuyen(n-1,nguon,dich,trunggian);
        chuyen(1,nguon,trunggian,dich);
        chuyen(n-1,trunggian,nguon,dich);
    }
}

int main(){
    int n;
    cout << "nhap vao so dia n: ";
    cin >> n;
    chuyen(n,'A','B','C');

    system("pause");
    return 0;
}