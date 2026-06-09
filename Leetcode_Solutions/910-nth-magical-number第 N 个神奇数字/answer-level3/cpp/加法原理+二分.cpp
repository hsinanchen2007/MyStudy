### 解题思路
1.题意很直接，就是我们要找个一个数M，M是能 被a整除 或者 被b整除 的第N个数字
2.我们先把问题，稍微变化一点，就是给你一个M，求M中有多少个数满足被a整除 或者 能被b整除 
3.对于2中的问题
（1）求出M中被a整除的数的数量：M/a
（2）求出M中被b整数的数的数量：M/b
 (3)求出M既能够被a，又能够被b整数的数的数量：M/Lcm(a,b) (Lcm(a,b) a，b的最小公倍数)

4.M中满足条件的数量为：Cnt=M/a+M/b-M/Lcm(a,b)（加法原理）

5.若Cnt==N，M%a==0 或 M%b==0,那M就是答案啦！！！

6.我们只需要二分M，即可
### 代码

```cpp
class Solution {
typedef long long ll;
public:
    ll gcd(ll a,ll b){
        return b==0?a:gcd(b,a%b);
    }
    ll lcm(ll a,ll b){
        return a/gcd(a,b)*b;
    }
    ll cnt(ll n,ll a,ll b){//n中满足条件的数量
        return n/a+n/b-n/lcm(a,b);
    }
    int nthMagicalNumber(int N, int A, int B) {
        ll l,r;
        ll md=1e9+7;
        l=2;r=4e14;
        while(l<=r){//二分找答案
            ll mid=(l+r)>>1;
            ll v=cnt(mid,A,B);
            if(v==N)
            {
                if(mid%A==0||mid%B==0)return mid%md;
                else r=mid-1;
            }
            else if(v<N)l=mid+1;
            else r=mid-1;
        }
    return -1;
    }
};
```