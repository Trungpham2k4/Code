// Cho mảng số nguyên A[] có N phần tử, hãy in ra các bước của thuật toán sắp xếp chọn.

// Input Format

// Dòng đầu tiên là số nguyên dương N. Dòng thứ 2 là N phần tử trong mảng, các phần tử viết cách nhau một dấu cách.

// Constraints

// 1<=N<=10^3; 0<=A[i]<=10^9

// Output Format

// In ra các bước của thuật toán sắp xếp chọn

// Sample Input 0

// 4
// 5 7 3 2
// Sample Output 0

// Buoc 1: 2 7 3 5
// Buoc 2: 2 3 7 5
// Buoc 3: 2 3 5 7

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int dem = 0;
    
    for(int i = 0; i < n-1;i++){
        int mini = i;
         // Find smallest element in unsorted list
        for(int j = i+1;j < n;j++ ){
            if(a[mini] > a[j]){
                mini = j;
            }
        }
        // Swap position of smallest element with first element
        swap(a[mini],a[i]);
        cout << "Buoc " << ++dem << ": ";
        for(auto x : a){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
