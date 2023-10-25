#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Ý tưởng merge sort: Chia mảng ra thành các mảng con và chia đến khi nào chỉ còn 1 phần tử duy nhất thì sẽ gộp lại 
void merge(int l, int r, int mid,int a[]){
    vector<int> v1(a + l, a + mid + 1);
    vector<int> v2(a + mid + 1, a + r + 1);
    int i = 0, j =0, k = 0;
    while(i < v1.size() && j < v2.size()){ 
        // vòng lặp này để sắp xếp các phần tử từ 2 mảng con phía trên thành 1 mảng lớn hơn
        // thay đổi luôn các phần tử từ chỉ số left trở đi
        if(v1[i] <= v2[j]){
            a[l] = v1[i];
            i++;
        }else{
            a[l] = v2[j];
            j++;
        }
        l++;
    }
    while(i < v1.size()){
        a[l++] = v1[i++];
    }
    while(j < v2.size()){
        a[l++] = v2[j++];
    }
}
void mergesort(int l, int r,int a[]){
    if(l >= r){return;} // đây là trường hợp mảng k thể chia được nữa, nó chỉ còn 1 phần tử duy nhất

    int mid = (l+ r)/2; // chia đôi mảng
    mergesort(l,mid,a); // tiếp tục chia đôi từ chỉ số left -> mid
    mergesort(mid+1,r,a); // chia đôi mảng con từ chỉ số mid + 1->right
    merge(l,r,mid,a); // khi đã chia xong các mảng con thì bắt đầu trộn
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    clock_t beginTime = clock() , endTime;
    mergesort(0,n,a);
    for(int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    endTime = clock(); // Thời gian kết thúc
    
    cout << (double)(endTime- beginTime)/ CLOCKS_PER_SEC ;
}