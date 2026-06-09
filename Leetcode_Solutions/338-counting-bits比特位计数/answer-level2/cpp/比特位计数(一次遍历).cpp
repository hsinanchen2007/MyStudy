### 解题思路
观察到每当走到i=2^n位置时，数字i的第n+1位为1，其他位为0，然后低位又重新递增，区别只是第n+1位多了一个1
故可以得到递推公式:dp[2^(n-1) + i] = dp[i] + 1,1 <= i <= 2^(n-1),且dp[2^n] = 1
### 代码

```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0) return {0};
        vector<int > res(num+1,0);
        res[1] = 1;
        for(int k = 0;k < 31;++k){
            int base = pow(2,k);
            for(int i = 1;i <= base;++i){
                if(base + i == res.size()){
                    return res;
                }
                if(i == base) {
                    res[2*i] = 1;
                    continue;
                }
                res[base + i] = res[i] + 1;
            }
        }
        return res;
    }
};
```