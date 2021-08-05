#include <iostream>
#include <vector>

using namespace std;

// [1, 2] mid0 [1] [2]
// [1, 2, 3] mid1 [1, 2] [3]

vector<int> sort_merge(vector<int>& left_arr, vector<int>& right_arr) {
    int arrs_size = left_arr.size() + right_arr.size();
    vector<int> result;
    if (left_arr.size() == 1 && right_arr.size() == 1) {
        if (right_arr[0] >= left_arr[0]) {
            result.push_back(left_arr[0]);
            result.push_back(right_arr[0]);
            return result;
        }
        else {
            result.push_back(right_arr[0]);
            result.push_back(left_arr[0]);
            return result;
        }
    }

    int r_ind = 0, l_ind = 0;
    for (int i = 0; i < arrs_size; i++) {
        if (r_ind >= right_arr.size() && l_ind >= left_arr.size()) {
            break;
        }
        if (r_ind >= right_arr.size()) {
            result.push_back(left_arr[l_ind]);
            l_ind++;
            continue;
        }
        if (l_ind >= left_arr.size()) {
            result.push_back(right_arr[r_ind]);
            r_ind++;
            continue;
        }
        if (left_arr[l_ind] >= right_arr[r_ind]) {
            result.push_back(right_arr[r_ind]);
            r_ind++;
        }
        else {
            result.push_back(left_arr[l_ind]);
            l_ind++;
        }
    }
    return result;
}

void split(vector<int>& array) {
    if (array.size() <= 1) return;
    int mid = (array.size() - 1) / 2;
    vector<int> left, right;
    for (int i = 0; i <= mid; i++) {
        left.push_back(array[i]);
    }
    for (int i = mid + 1; i < array.size(); i++) {
        right.push_back(array[i]);
    }
    split(left);
    split(right);
    array = sort_merge(left, right);
}
// [1,2,3,4]
// [7,8] [3,4]
void sort(vector<int>& array) {
    split(array);
}


void print_vector(const std::vector<int>& data) {
    for (int i : data) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(void) {
    int n;
    cout << "N of sequence to sort: ";
    cin >> n;
    if (n < 0) {
        cout << "No";
        return 0;
    }
    vector<int> arr(n);
    cout << "Sequence: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array before sorting:" << endl;
    print_vector(arr);
    sort(arr);
    cout << "Array after sorting:" << endl;
    print_vector(arr);

    return 0;
}