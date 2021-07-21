#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    string instance;
    ifstream f("input.txt");

    if(f.is_open()){
        while(getline(f,instance)){
            stringstream ss(instance);
            int target;
            vector<int> arr;
            while(ss>>target){
                arr.push_back(target);
            }
        }
        f.close();
    }
    else{
        cout<<"can't open file...";
    }
    return 0;
}