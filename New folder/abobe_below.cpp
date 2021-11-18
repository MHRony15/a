#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
    ofstream fileout;
    ifstream filein;
    fileout.open("above.txt");
    int n,test,X,a,c;
    cout<<"Enter the number of sample: ";
    cin>>n;
    cout<<"Enter 1 for LCM or 2 for buildin: ";
    cin>>test;
    int m = 100;
    if(test == 1){
        cout<<"Enter Seed Multipicator and incrimenter: ";
        cin>>X>>a>>c;
        X = (a * X + c) % m;
        fileout<<X<<" ";
    }
    else{
        for (int i = 0; i < n;i ++){
            X = rand() % m;
            fileout<<X<<" ";
        }

    }
    fileout.close();
    filein.open("above.txt");
    int tmp,flag = 0,run = 0,average,n1=0,n2=0;
    average = (m - 1) / 2;
    for( int i = 0; i < n; i++){
        filein>>X;
        if(X>average) n1++;
        else n2++;
        if(X > average && flag == 0){
            run++;
            flag = 1;
        }
        else if((average > X && flag == 1) || (flag == 0 && i == 0)){
            run++;
            flag = 0;

        }
    }
    double mean,SD,randomness,Z;
    mean = ((2 * n1 * n2) / n) + 1 / 2;
    SD = sqrt(2 * n1 * n2 * (2 * n1 * n2 - n ) / (n * n * (n - 1)));
    randomness = (run - mean) / SD;
    cout<<"Enter Z value: ";
    cin>>Z;
    if(randomness > -Z && randomness < Z) cout<<"ACCPTED";
    else cout<<"REJECTED";
   // cout<<n1<< " "<<n2<< " "<<run<< " "<<mean<< " "<<SD<< " "<<randomness;


    return 0;
}
