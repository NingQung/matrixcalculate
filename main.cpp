#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    float x=0;
    while(true){
        cout << "�x�}�B����@�N" << endl << "���k �Ы�1 �F n���� �Ы�2 �F �G���Ϥ�} �Ы�3 �F " << endl << "�h�X�Ы�0" << endl;
        int sta;
        cin >> sta;
        if (sta == 1){
            cout << "�w�Ұʯx�}���k�A�ثe�Ȥ䴩���"<< endl;
            while (true){
            cout << "�p�n�h�X�A�Ы���J0,0"<< endl;
            cin >> a >> b;
            if (a==0 && b==0){break;}
            cin >> c >> d;
             if(b != c){
                cout << "�L�k�i��B��"<< endl;
            }
            else{
            int mata[a][b];
            for(int i=0; i<a; i++){ //mata in
                for(int j=0; j<b; j++){
                    cin >> mata[i][j];
                }
            }
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

            //_sleep(1000);
            //cout << endl;
            //for(int i=0; i<a; i++){for(int j=0; j<b; j++){cout<<mata[i][j]<<" ";}cout<<endl;} cout<<endl;
            //for(int i=0; i<c; i++){for(int j=0; j<d; j++){cout<<matb[i][j]<<" ";}cout<<endl;} cout<<endl;
            }
        }
        else if (sta == 2){
            cout << "�x�}n����p�u��" << endl << "a*a���x�}�An����A�p�ݳv�@��ܡA�Ы�0" << endl <<"��J�d��:a n b" << endl;
            int n;
            cin >> a >> n >> b;
            if (a==0){break;}
            float mata[a][a];
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

            //for(int i=0; i<a; i++){for(int j=0; j<a; j++){cout<<mata[i][j]<<" ";}cout<<endl;} cout<<endl;
            //for(int i=0; i<a; i++){for(int j=0; j<a; j++){cout<<matb[i][j]<<" ";}cout<<endl;} cout<<endl;
        }
        else if (sta == 3){
            int matr[2][2];
            int e=0;
            cout << "������J�G���x�}�Y�i" << endl;
            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++){
                    cin >> matr[i][j];
                }
            }
            e = matr[0][0]*matr[1][1]-matr[1][0]*matr[0][1];
            x = matr[0][0]; matr[0][0]=matr[1][1]; matr[1][1]=x;
            matr[1][0] = -matr[1][0]; matr[0][1] = -matr[0][1];
            //for(int i=0; i<2; i++){for(int j=0; j<2; j++){cout<<matr[i][j]<<" ";}cout<<endl;}
            for(int i=0; i<2; i++){
                for(int j=0; j<2; j++){
                    if(matr[i][j]%e == 0){
                        cout << matr[i][j]/e << " ";
                    }
                    else{
                        cout << matr[i][j] << "/" << e << " ";
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


