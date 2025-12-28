#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void radix_sort(vector<int>& arr, int k){
    int size = arr.size();
    int exp = 1;

    for(int pos = 0;pos<k;pos++){
        vector<int> arr_new[10]; //정수 vector가 10개 있는 배열 만들기

        for(int i=0;i<size;i++){
            int digit = (arr[i]/exp)%10; //해당 자릿수 숫자 구함
            arr_new[digit].push_back(arr[i]); //구한 자릿수의 숫자 배열에 삽입
        }

       vector<int> store_arr;
       for(int i=0;i<10;i++){
            for(int j=0;j < arr_new[i].size();j++){ //.size만큼만 돌아서 값있는곳만 탐색
                store_arr.push_back(arr_new[i][j]); //자릿수 정렬된 숫자들을 다시 일차원 vector에 삽입
        }
        arr = store_arr; //복사
        exp*=10; //다음 자릿수
       }
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

    
    int max_val = *max_element(arr.begin(), arr.end()); // k 계산
    int k = 0;
    while (max_val > 0) {
        max_val /= 10;
        k++;
    }
    radix_sort(arr, k);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}