#include <iostream>
#include <vector>

using namespace std;

bool if_unique(vector<int> arr){
    int c = 0;
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < i; j++){
            if(arr[i] == arr[j]){
                c++;
                break;
            }
        }
    }
    if(c == 0){
        return true;
    }
    return false;
}

int main(void){
    cout << "Write length of array";
    int n;
    cin >> n;
    if (n < 0){
        cout << "No" << endl;
        return 0;
    }
    vector<int> array(n);
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    
    cout << "Unique?" << endl << if_unique(array);
    return 0;
}