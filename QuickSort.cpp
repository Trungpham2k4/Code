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

// Phân hoạch Lomuto
int Lomuto_Partition(int a[], int l, int r){
    // Ý tưởng: Tìm phần tử nhỏ hơn hoặc bằng pivot, nếu tìm được thì swap vị trí cần tìm với phần tử lớn hơn pivot đã bỏ qua
    // trước đó
    int i = l - 1;
    for(int j = l; j < r;j++){
        if(a[j] <= a[r]){
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[r],a[i]); // swap phần tử ở i với phần tử pivot nằm ở cuối mảng
    return i;
}


// Phân hoạch Hoare
int Hoare_Partition(int a[], int l, int r){
    // Ý tưởng: Tìm cặp nghịch thế trong mảng sau đó hoán đổi vị trí 2 phần tử đó cho đến khi l == r
    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;
    while(true){
        do{
            i++;
        }while(a[i] < pivot);
        do{
            j--;
        }while(a[j] > pivot);
        if(i < j){
            swap(a[i],a[j]);
        }else{
            return j;
        }
    }
    return j;
}
void QuickSort_Lomuto(int a[], int l,int r){
    
    if(l < r){
        int pivot = Lomuto_Partition(a,l,r);
        QuickSort_Lomuto(a,l,pivot-1);
        QuickSort_Lomuto(a,pivot+1,r);
    }else{
        return;
    }
    
}
void QuickSort_Hoare(int a[], int l,int r){
    
    if(l < r){
        int pivot = Hoare_Partition(a,l,r);
        QuickSort_Hoare(a,l,pivot);
        QuickSort_Hoare(a,pivot+1,r);
    }else{
        return;
    }
    
}
int main() {
    int n = 10;
    int a[] = {3,4,2,1,5,7,9,8,6,1};
    QuickSort_Hoare(a,0,n-1);
    for(int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
}