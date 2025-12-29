#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high)
{
    vector<int> merged_arr(high+1);
    int i= low;
    int j =mid+1;
    int k = low;

    while(i<=mid&&j<=high){
        if(arr[i]<=arr[j]){
            merged_arr[k]=arr[i];
            k+=1;
            i+=1;
        }
        else{
            merged_arr[k]=arr[j];
            k+=1;
            j+=1;
        }
    }
    while(i<=mid){
        merged_arr[k]=arr[i];
        k+=1;
        i+=1;
    }
    while(j<=high){
        merged_arr[k]=arr[j];
        k+=1;
        j+=1;
    }
    for(k=low;k<=high;k++)
        arr[k]=merged_arr[k];
}

void merge_sort(vector<int> &arr, int low, int high)
{
    if(low<high){
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
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
    
    merge_sort(arr, 0, n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}
