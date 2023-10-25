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
void ShellSort(pair<int,string> a[], int n){
  int gap = n/2;
  while(gap > 0){
    for(int i = gap; i < n;i++){
      pair<int,string> temp = a[i];
      int j = i;
      //|| (a[j-gap].second > temp.second && abs(a[j - gap].first) == abs(temp.first)) // tăng dần
      // &&((abs(a[j - gap].first) < abs(temp.first))) || ((a[j-gap].second > temp.second) && (abs(a[j - gap].first) == abs(temp.first))) // Sắp xêm giảm dần
      step++;
      while(j > gap-1 ){// Giảm dần
        if( ((abs(a[j - gap].first) >= abs(temp.first))) && ((abs(a[j - gap].first) != abs(temp.first)) || (a[j-gap].second < temp.second))) break;
        a[j] = a[j-gap];
        j-=gap; 
        step++;
      }
      a[j] = temp;
      step++;
    }
    gap/=2;
  }
}
// ty--4
// mw--3
// bb-3
// ft-3
// io-1
// cn-1
// sj-2
// rp--10
int main() {
  int n = 8;
  pair<int,string> a[] = {{-4,"A"},{-3,"B"},{3,"C"},{3,"D"},{1,"E"},{1,"F"},{2,"G"},{-10,"H"},{19,"I"},{7,"K"}};
  ShellSort(a,n);
  for(int i = 0; i < n; i++){
    cout << a[i].first << " " << a[i].second << endl;
  }
  cout << step;
}