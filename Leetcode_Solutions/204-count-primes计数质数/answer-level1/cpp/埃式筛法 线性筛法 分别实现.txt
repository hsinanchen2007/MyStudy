### 解题思路


### 代码

```cpp
class Solution {
public:
/*
    //埃式筛法 O(nlog(log(n)))
    int countPrimes(int n) {
        if(n <= 2)return 0;
        vector<bool> st(n,false);
        int ans = 0;
        for(int i = 2;i < n;++i){
            if(!st[i]){
                ++ans;
                for(int j = i + i;j <= n;j += i) st[j] = true;
            }
        }
        return ans;
    }
*/
    //线性筛法 On
    int countPrimes(int n) {
        if(n <= 2)return 0;
        vector<bool> st(n, false);
        vector<int> prime;
        int ans = 0;
        for(int i = 2;i < n;++i){
            if(!st[i]){
                ++ans;
                prime.push_back(i);
            }
            for(int j = 0;prime[j] <= n / i;++j){
                st[i * prime[j]] = true;
                if(i % prime[j] == 0)break;
            }
        }
        return ans;
    }
};
```