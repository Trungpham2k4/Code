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
int step = 0;
void insort(int a[], int n,int segment, int incre){ // segment là chỉ số của phần tử bắt đầu của sublist, incre là gap 
    for(int i = segment+incre; i < n;i+= incre){// Trong sublist có nhiều đoạn nên sẽ để tăng đến các vị trí trong sublist 
        for(int j = i;j >= incre && a[j] < a[j-incre]; j-= incre){
            swap(a[j],a[j-incre]);
            step++;
        }
        for(int k = 0; k < 8;k++){
            cout << a[k] << " ";
        }
        cout << endl;
    }
    
}
void shellsort(pair<int,string> a[], int n){
    for(int i = n/2; i >= 1; i/=2){ //gap
        for(int j = 0; j < i;j++){
            //insort(a,n,j,i);
            for(int k = i+j;k < n; k+=i){
                // for(int m = k; m >= i && a[m] > a[m-i];m-=i){
                //     swap(a[m],a[m-i]);
                //     step++;
                // }
                int m = k;
                //&& (abs(a[m].first) > abs(a[m-i].first)) || ((abs(a[m].first) == abs(a[m-i].first)) && (a[m-i].second > a[m].second) )
                while(m >= i ){
                    if( ((abs(a[m - i].first) >= abs(a[m].first))) && ((abs(a[m-i].first) != abs(a[m].first)) || (a[m-i].second < a[m].second))) break;
                    swap(a[m],a[m-i]);
                    step++;
                    m-=i;
                    for(int i = 0; i < n;i++){
                        cout << a[i].first << " ";
                    }
                    cout << endl;
                }
            }
        }
    }

    // for(int i = 1; i<n;i++){
    //     int j = i;
    //     while(j >= 1 && a[j] > a[j-1]){
    //         swap(a[j],a[j-1]);
    //         step++;
    //         j--;
    //     }
    // }
}

// ty--4: 9
// mw--3: 8
// bb-3: 7
// ft-3:6
// io-1:4
// cn-1:3
// sj-2:5
// rp--10
void shellsort(int a[],int n){
    for(int i = n/2; i > 2; i/=2){ //gap
        for(int j = 0; j < i;j++){
            insort(a,n,j,i);
        }
    }
    insort(a,n,0,1);
    for(int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << step;
}
int main() { 
    int a[] = {9,8,7,6,4,3,5,10};
    int b[] = {26,37,13,18,71};
    pair<int,string> c[] = {{9,"A"},{8,"B"},{7,"C"},{6,"D"},{4,"E"},{3,"F"},{5,"G"},{-10,"H"},{19,"I"},{7,"K"}};
    int n = 8;
    // shellsort(c,n);
    // for(int i = 0; i < n;i++){
    //     cout << c[i].first << " " << c[i].second << endl;
    // }
    // cout << endl;
    // cout << step;
    shellsort(a,6);
}