#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define pll pair<ll,ll>
#define all(a) (a).begin(),(a).end()
#define F first
#define S second
#define oset ordered_set
#define rep(i,j,k) for(ll i=j;i<k;i++)
#define endl "\n"

// Visualize thuật toán này bằng cách vẽ cây nhị phân hoàn chỉnh 
void heapify(int a[],int n, int i){
    int left = 2 * i + 1; // Chỉ số của node con trái
    int right = 2 * i + 2; // Chỉ số của node con phải
    int largest = i; // tạo biến để tìm chỉ số của phần tử max
    // cập nhật chỉ số nếu 1 trong 2 node lớn hơn node cha
    if(left < n && a[left] > a[largest]){ 
        largest = left;
    }
    if(right < n && a[right] > a[largest]){
        largest = right;
    }
    if(largest != i){ // Nếu như node lớn nhất k phải node cha thì sẽ swap và gọi heapify đến vị trí của phần tử mới swap
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
// i = n/2 - 1: Bát đầu từ nhứng node có con trái hoặc con phải
void HeapSort(int a[],int n){
    // Build Max Heap
    for(int i = n/2 - 1; i >= 0;i--){
        heapify(a,n,i);
    }
    cout << "Step 0: ";
    for(int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    int k = 1;
    for(int i = n - 1; i >= 0;i--){
        cout << "Step " << k++ << ": ";
        for(int j = 0; j < n;j++){
            cout << a[j] << " ";
        }
        cout << endl;
        swap(a[i],a[0]);
        heapify(a,i,0); // O(log(N))
        
    }
}
int main() {
    int a[] = {9,5,3,2,8,7,6,4,1};
    int n = 9;
    HeapSort(a,n); // O(NLog(N))
    
}