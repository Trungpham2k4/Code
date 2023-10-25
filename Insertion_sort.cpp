// Cho mảng số nguyên A[] có N phần tử, hãy in ra các bước của thuật toán sắp xếp chèn

// Input Format

// Dòng đầu tiên là số nguyên dương N. Dòng thứ 2 là N phần tử trong mảng, các phần tử viết cách nhau một dấu cách.

// Constraints

// 1<=N<=10^3; 0<=A[i]<=10^9

// Output Format

// In ra các bước của thuật toán sắp xếp chèn

// Sample Input 0

// 7
// 56 73 15 64 86 61 50 
// Sample Output 0

// Buoc 1: 56 73 15 64 86 61 50 
// Buoc 2: 15 56 73 64 86 61 50 
// Buoc 3: 15 56 64 73 86 61 50 
// Buoc 4: 15 56 64 73 86 61 50 
// Buoc 5: 15 56 61 64 73 86 50 
// Buoc 6: 15 50 56 61 64 73 86 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        int r = rand();
        a[i] = r;
    }
    int dem = 0;
    clock_t beginTime = clock() , endTime;
    for(int i = 1; i < n;i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key ){
            a[j+1] = a[j];
            j = j -1;
        }
        a[j+1] = key;
        cout << "Buoc " << ++dem << ": ";
        for(int k = 0;k < n;k++){
            cout << a[k] << " ";
        }
        cout << endl;
    }
    endTime = clock();
    cout << (double)(endTime- beginTime)/ CLOCKS_PER_SEC ;
    return 0;
}
