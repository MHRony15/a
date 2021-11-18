#include<bits/stdc++.h>
using namespace std;
#define MX 100000

int  occurrence[MX];
int main(){
        ofstream fileout;
        ifstream filein,filein2;
        fileout.open("output.txt");
        int s,n,m,X,a,c,i,rang,ex,in,tmp;
        double total,chi;
        cout<<"Enter the number of Random Number: ";
        cin>>n;
        cout<<"Enter 1 for LCM or 2 for BuildIn random generator:";
        cin>>s;
        m=100;
        if(s==1){
            cout<<"Enter seed multiplier increamenter: ";
                cin>>X>>a>>c;
            for(i=0;i<n;i++){
                X=(a*X+c)%m;
                fileout<<X<<" ";
            }
        }

        else{
            for(int i=0;i<n;i++){
                    X = rand()%m;
                fileout<<X<<" ";
            }
        }
        fileout.close();
        filein.open("output.txt");
        rang=10;
       int rengDif=m/rang;
        ex=n/rang;
        //fstream("output.txt","w",stdout);
        for(int i = 0; i < n; i++){
            filein>>X;
            cout<<X<<" ";
            in=X/rengDif;
            occurrence[in]++;
        }
        for(int i = 0;i<rang;i++){
            tmp = (occurrence[i]-ex)*(occurrence[i]-ex);
            chi= (double)tmp/(double)ex;
            total= total+chi;
        }
        if(total>=1.73 && total <= 23.6){
            cout<<"Result : ACCEPTED";
        }
        else{
            cout<<"Result : NOT ACCEPTED";
        }

return 0;
}
