#include <bits/stdc++.h>
 
typedef long long int ll;
typedef long double ld;
using namespace std;
//#define P 1000000007
#define P 998244353
#define rep(i,n) for(i=0;i<n;++i)
#define re(i,a,n) for(i=a;i<=n;++i)
#define repr(i,a,n) for(i=a;i>=n;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
#define ub(v,val) upper_bound(v.begin(),v.end(),val)
#define np(str) next_permutation(str.begin(),str.end())
#define lb(v,val) lower_bound(v.begin(),v.end(),val)
#define sortv(vec) sort(vec.begin(),vec.end())
#define rev(p) reverse(p.begin(),p.end());
#define mset(a,val) memset(a,val,sizeof(a));
#define at(s,pos) *(s.find_by_order(pos))
#define set_ind(s,val) s.order_of_key(val)
#define PI 3.14159265
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
// #include <ext/pb_ds/assoc_container.hpp> // Common file  
// #include <ext/pb_ds/tree_policy.hpp>  
// #include <functional> // for less  
// #include <iostream>  
// // Important header files   
// using namespace __gnu_pbds;  
// using namespace std;  
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
ll binpowmod(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
 
 
 
long long modInverse(unsigned long long n, 
                                            ll p)
{
    return binpowmod(n, p - 2, p);
}
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
 
long long lcm(long long x,long long y, long long z)
{
        long long max,lcom, count, flag=0;
        if(x>=y&&x>=z)
                max=x;
        else if(y>=x&&y>=z)
                max=y;
        else if(z>=x&&z>=y)
                max=z;
        for(count=1;flag==0;count++)
        {
                lcom=max*count;
                if(lcom%x==0 && lcom%y==0 && lcom%z==0)
                {
                        flag=1;
                }
        }
        return lcom;
}
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if(a.first == b.first) return (a.second<b.second);
    return (a.first < b.first);
}


 
int main() 
{
  IOS;
  #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
 
  int a,b,c,d,e,f,g,h,i,j,k,l,n,o,p,q,r,t,u,v,w,x,y,z,tc,ans,count,sum;
  string s="", st="", str="";
  tc=1;
  cin >> tc ;
 
 
  while(tc--)
  {
      int n;
      cin>>n;
      vector<int>v(n);
      int ans=0;
      for(int i=0;i<n;i++)cin>>v[i];
      
      cout<<ans<<"\n";
      

    
  }
 
 
  return 0 ;
}