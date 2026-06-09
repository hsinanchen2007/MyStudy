### 解题思路
贪心
mx[i]表示能覆盖到这个点的同时能覆盖到的最远的点是哪个
![image.png](https://pic.leetcode-cn.com/f80a8fa943e1608207b08231ff9cdda149fc463e2aaa1bbe2662d8cd1ca1d962-image.png)

### 代码

```cpp
#include<bits/stdc++.h>
#define de(x) cout<<#x<<"="<<x<<endl
#define dd(x) cout<<#x<<"="<<x<<" "
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define repd(i,a,b) for(int i=a;i>=(b);--i)
#define repp(i,a,b,t) for(int i=a;i<(b);i+=t)
#define mt(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp(u,v) make_pair(u,v)
#define sz(a) (int)a.size()
#define pb push_back
#define PI acos(-1.0)
#define qc std::ios::sync_with_stdio(false)
#define all(a) a.begin(),a.end()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
class Solution {
    int mx[10006];
public:
    int minTaps(int n, vector<int>& R) {
        mt(mx, -1);
        rep(i, 0, n + 1) {
            int l = max(i - R[i], 0), r = min(i + R[i], n);
            rep(j, l, r + 1) {
                mx[j] = max(mx[j], r);
            }
        }
        int cur = 0, ret = 0;
        while(true) {
            if(cur == mx[cur]) return -1;
            cur = mx[cur];
            ret++;
            if(cur >= n) return ret;
        }
        return -1;
    }
};
```