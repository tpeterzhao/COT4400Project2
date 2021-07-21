#include <vector>
#include <iostream>
using namespace std;

int t=7;
int n=3;
vector< vector<int> > arr(t+1, vector<int> (n+1, -1));
int main(){
    vector<int> data;
    data.push_back(0);
    data.push_back(5);
    data.push_back(2);
    data.push_back(1);
    for (int i =0; i<=t; i++){
        for(int j = 0; j<=n; j++){
            if(i==0){
                arr[i][j] = 1;
            } else if (j==0){
                arr[i][j] = 0;
            } else if( data[j]==0 || i<j){
                arr[i][j] = arr[i][j-1];
            } else{
                arr[i][j] = arr[i-j][j]+arr[i][j-1];
            }
        }
    }

    cout<<arr[t][n]<<endl;
}