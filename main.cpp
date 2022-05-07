#include<iostream>
#include<math.h>
using namespace std;
int divider(int a,int b){
    int ta;
    while (true)
    {
        if(a < b){
            ta = a;
            a = b;
            b = ta;
        }
        for(int i = 0;a > b; i++){
            a = a - b;
        }
        if(a ==0 || a==b){
            return b;
            break;
        }
    }
}
int main()
{
    int a,b,c,d;
    float x=0;
    while(true){
        cout << "矩陣運算機一代" << endl << "乘法 請按1 ； n次方 請按2 ； 二階反方陣 請按3 ； " << endl << "退出請按0" << endl;
        int sta;
        cin >> sta;
        if (sta == 1){
            cout << "已啟動矩陣乘法，目前僅支援整數\n請輸入兩個矩陣的大小(行×列)"<< endl;
            while (true){
                cout << "如要退出，請按輸入0 0"<< endl;
                cin >> a >> b;
                if (a==0 && b==0){
                    break;
                    }
                cin >> c >> d;
                if(b != c){
                    cout << "無法進行運算"<< endl;
                }
                else{
                    cout << "請輸入矩陣：" << a << "×" << b << endl;
                    int mata[a][b];
                    for(int i=0; i<a; i++){ //mata in
                        for(int j=0; j<b; j++){
                        cin >> mata[i][j];
                        }
                    }
                    cout << "請輸入矩陣：" << c << "×" << d << endl;
                    int matb[c][d];
                    for(int i=0; i<c; i++){ //matb in
                        for(int j=0; j<d; j++){
                            cin >> matb[i][j];
                        }
                    }
                    //MatrixMultiple
                    int mato[a][d];
                    for(int i=0; i<a; i++){
                        for(int j=0; j<d; j++){
                            for(int k=0; k<b; k++){
                                x = x + mata[i][k]*matb[k][j];
                            }
                            mato[i][j] = x;
                            x=0;
                        }
                    }
                    cout << endl;
                    for(int i=0; i<a; i++){for(int j=0; j<d; j++){cout<<mato[i][j]<<" ";}cout<<endl;}
                }
            }
        }
        else if (sta == 2){
            cout << "矩陣n次方小工具" << endl << "a*a階矩陣，n次方，如需逐一顯示，請按0、否則請按1" << endl <<"輸入範例:a n 0" << endl;
            int n;
            cin >> a >> n >> b;
            if (a==0){break;}
            float mata[a][a];
            cout << "請輸入" << a << "階方陣" << endl;
            for(int i=0; i<a; i++){ //mata in
                for(int j=0; j<a; j++){
                    cin >> mata[i][j];
                }
            }
            float matb[a][a];
            for(int i=0; i<a; i++){ //mata to matb
                for(int j=0; j<a; j++){
                    matb[i][j] = mata[i][j];
                }
            }
            float mato[a][a];
            for(int h=1; h<n; h++){ //mat^n
                for(int i=0; i<a; i++){ //mata*matb
                    for(int j=0; j<a; j++){
                        for(int k=0; k<a; k++){
                            x = x + mata[i][k]*matb[k][j];
                        }
                        mato[i][j] = x;
                        x=0;
                    }
                }
                for(int i=0; i<a; i++){ //mato to mata
                    for(int j=0; j<a; j++){
                        mata[i][j] = mato[i][j];
                    }
                }
                if(b==0){
                    cout<<endl;
                    cout << "n=" << h+1 << endl;
                    for(int i=0; i<a; i++){for(int j=0; j<a; j++){cout<<mata[i][j]<<" ";}cout<<endl;}
                }
                else{
                    if (h == n-1){cout<<endl; for(int i=0; i<a; i++){for(int j=0; j<a; j++){cout<<mata[i][j]<<" ";}cout<<endl;}}
                }
            }
        }
        else if (sta == 3){
            int matr[2][2];
            int e=0;
            cout << "直接輸入二階矩陣即可" << endl;
            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++){
                    cin >> matr[i][j];
                }
            }
            e = matr[0][0]*matr[1][1]-matr[1][0]*matr[0][1];
            x = matr[0][0]; matr[0][0]=matr[1][1]; matr[1][1]=x;
            matr[1][0] = -matr[1][0]; matr[0][1] = -matr[0][1];
            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++){
                    if(matr[i][j]%e == 0){
                        cout << matr[i][j]/e << " ";
                    }
                    else{
                        int abma = abs(matr[i][j]);
                        int abe = abs(e);
                        int lcm = divider(abma,abe);
                        if(lcm = 1){
                            cout << matr[i][j]<< "/" << e << " ";
                        }else{
                            cout << matr[i][j]/lcm<< "/" << e/lcm << " ";
                        }
                    }
                }
                cout << endl;
            }
        }
        else if (sta == 0){
            break;
        }
    }
    return 0;
}
