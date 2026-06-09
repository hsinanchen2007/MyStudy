一般使用的埃氏筛选法复杂度为 O(N * loglogN)，这里给出线性筛选法代码：
```
class Solution {
public:
    bool st[10000000];
    int cnt=0,prime[10000000];
    void get_prime(int n){
        fill(st,st+10000000,true);
        st[1]=false;
        for(int i=2;i<n;++i){
            if(st[i]) prime[cnt++]=i;
            for(int j=0;prime[j]<=n/i;++j){
                st[prime[j]*i]=false;              //此时prime[j]是prime[j]*i的最小质数
                if(i%prime[j]==0)break;            
            }
        }
    }
    int countPrimes(int n) {
        get_prime(n);
        return cnt;
    }
};
```
思路为，每一个数用其质因数分解的最小质数进行判断，例如12用2判断即可，埃氏筛选法的做法12将会被2和3同时判断一次。此做法因为每个数最多被判断一次，所以复杂度为O(N)。