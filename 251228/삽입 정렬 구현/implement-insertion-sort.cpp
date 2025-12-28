#include <iostream>
#include <iterator>

#define MAX_N 100

using namespace std;

int n;
int arr[MAX_N];

void insert_sorting()
{
    int size = n;
    for (int i=1;i<n;i++){
        int j = i-1;
        int key = arr[i];
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insert_sorting();
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
