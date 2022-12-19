![QQ图片20191030114827.png](https://pic.leetcode-cn.com/6a13e4d07a2360c634ca53a21b85eb004f75e85906e03c14f3fb3a2afc264e99-QQ%E5%9B%BE%E7%89%8720191030114827.png)


```
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k=primes.size();
        vector<int> vec(n,1);
        vector<int> id(k,0);
        vector<int> v(primes);

        int cnt=1;

        while(cnt<n)
        {
            int t_id=0;
            for(int i=1;i<k;++i)
            {
                 if(v[t_id]>v[i])
                 {
                     t_id=i;
                 }
                 else if(v[t_id]==v[i])
                 {
                     v[i]=vec[++id[i]]*primes[i];
                 }
            }
            vec[cnt++]=v[t_id];

            v[t_id]=vec[++id[t_id]]*primes[t_id];
        }

        return vec[n-1];
    }
};
```
