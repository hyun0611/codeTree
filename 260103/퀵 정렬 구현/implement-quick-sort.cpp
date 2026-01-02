#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int select_pivot(vector<int>& arr, int low, int high) {
    int count = high - low + 1;
    if (count <= 3) 
        return high; 

    int mid = low + (high - low) / 2;

    int a = arr[low], b = arr[mid], c = arr[high];

    if ((a - b) * (c - a) >= 0) 
        return low;    
    else if ((b - a) * (c - b) >= 0)
        return mid;
    else 
        return high;                   
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = select_pivot(arr, low, high);
    int pivotValue = arr[pivot]; // 피벗의 '값'을 보관

    swap(arr[pivot], arr[high]); //마지막으로 보냄

    int i = low - 1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivotValue){
            i+=1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if(low<high){
        int pos = partition(arr, low, high);

        quick_sort(arr, low, pos-1);
        quick_sort(arr, pos+1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }

    quick_sort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
