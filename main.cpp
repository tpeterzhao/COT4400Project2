#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int SubsetSum(int , int, vector<int>);
int MemoSubsetSum(int, int, vector<int>, vector< vector<int> >);

int main(){
    string instance;
    ifstream f("input.txt");

    if(f.is_open()){
        // read first line of file that indicates the number of instance in the file
        getline(f,instance);
        // first
        getline(f, instance);
        // second
        getline(f, instance);
        // third
        getline(f, instance);
        // fouth
        getline(f, instance);
        // read instances
            stringstream ss(instance);
            int target;
            vector<int> arr;
            // read each instance into an int vector
            ss>>target;
            int max;
            ss>>max;
            int entry;
            arr.push_back(0);
            while(ss>>entry){
                arr.push_back(entry);
            }
            // calculate the subset sum of the instance
            cout<<"Target: "<<target<<" Max: "<<max<<endl;
            cout<<SubsetSum(target,max,arr)<<endl;
        f.close();
    }
    else{
        cout<<"can't open file...";
    }
    return 0;
}

int SubsetSum(int t, int n, vector<int> data){
    vector< vector<int> > S(t+1, vector<int> (n+1,-1));
    return MemoSubsetSum(t, n, data, S);
}

int MemoSubsetSum(int t, int n, vector<int> data, vector< vector<int> > S){
    cout<<"Target: "<<t<<" Max: "<<n<<endl;
    for (std::vector<int>::const_iterator i = data.begin(); i != data.end(); ++i){
        std::cout << *i << ' ';
    }
    cout<<endl;
    //return value stored in S if the cell is already filled int
    if(S[t][n] != -1){
        return S[t][n];
    }
    if(t == 0){
        S[t][n] = 1;
    }else if(n == 0){
        S[t][n] = 0;
    } else if(data[n]==0 || t<n){
        S[t][n] = MemoSubsetSum(t,n-1, data, S);
    } else{
        vector<int> data1(data);
        data1[n] = data[n]-1;
        int  sum1 = MemoSubsetSum(t-n, n, data1, S);
        int sum2 = MemoSubsetSum(t, n-1, data, S);
        S[t][n] = sum1+sum2;
    }
    return S[t][n];
}