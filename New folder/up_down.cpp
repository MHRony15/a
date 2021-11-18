#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
    ofstream fileout;
    ifstream filein;
    fileout.open("up_down.txt");
    int n,cx,X,a,c,tmp,flag,run;
    cout<<"Enter the number of sample:";
    cin>>n;
    cout<<"Enter 1 for LCM or 2 Buildin: ";
    cin>>cx;
    int m = 100;
    if(c==1){
        cout<<"Enter seed multiplier increamenter: ";
        cin>>X>>a>>c;
        for(int i = 0;i < n;i++ ){
            X = (a * X + c) % m;
            fileout<<X<<" ";
        }
    }
    else{
        for(int i = 0;i < n;i ++){
            X = rand() % m;
            fileout<<X<<" ";
        }

    }
    fileout.close();
    filein.open("up_down.txt");
    flag = 0;
    run = 0;

    filein>>X;
    tmp = X;
    for(int i = 1;i < n-1;i ++){
        filein>>X;
        if(X > tmp && flag == 0){
            run++;
            flag = 1;
        }
        else if (tmp > X && flag == 1){
            run++;
            flag = 0;
        }
        tmp = X;

    }
    double mean, SD,Z,Randomness;
    mean = (2 * n -1) / 3;
    SD = sqrt((16 * n - 29) / 90);
    Randomness = (run - mean) / SD;
    cout<<"Z value: ";
    cin>>Z;
    if(Randomness > -Z && Randomness < Z) cout<<"Accepted";
    else cout<<"REJECTED";
    return 0l;
}
