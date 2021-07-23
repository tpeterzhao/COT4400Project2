#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int SubsetSum(int, int);
int RecSubsetSum(int, int);

int * S;
int * entries;
int length;

int main(){
    string line;
    ifstream f("input.txt");
    if(f.is_open()){
        // read first line of file
        getline(f, line);

        // read each instance
        while(getline(f,line)){
            // read target and max of each instance
            int target;
            int max;
            stringstream ss(line);
            ss>>target;
            ss>>max;
            cout<<"Target: "<<target<<" Max: "<<max<<endl;
            length = max+1;
            // read data of each instance
            entries = new int[max+1];
            for(int i=1; i<=max; i++){
                ss>>entries[i];
            }
            cout<<SubsetSum(target,max)<<endl;
        }
    } else{
        cout<<"File can not be opened."<<endl;
    }
    f.clear();
    return 0;
}

int SubsetSum(int t, int n){
    // initialize 2d array to -1
    S = new int[(t+1)*(n+1)];
    memset(S, 0, (t+1)*(n+1)*sizeof(int));
    // calculate subsum recursively
    return RecSubsetSum(t,n);
}

int RecSubsetSum(int t, int n){
    // return 1 if target value is reached
    if(t==0){
        S[t*length+n] = 1;
    } else if(n<=0) {       // return 0 if max value is 0 or less
        S[t*length+n] = 0;
    }else if(S[t*length+n] == 0){   // calculate subsum value and store into array if current value in array is 0
        for(int i=0; i<= entries[n]; i++){
            // break if exceeds target value
            if(t-i*n < 0) break;
            // calculate sub sum recursively and store in array
            S[t*length+n] += RecSubsetSum(t-i*n, n-1);
        }
    }
    // return value of array
    return S[t*length+n];
}