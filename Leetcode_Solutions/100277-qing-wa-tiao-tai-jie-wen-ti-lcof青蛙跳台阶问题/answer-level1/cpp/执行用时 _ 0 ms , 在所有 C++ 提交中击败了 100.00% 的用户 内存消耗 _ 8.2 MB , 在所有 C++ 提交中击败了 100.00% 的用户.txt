### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public: 
    int numWays(int n) {
    long long sum[10000];
    sum[0] = 1;
    sum[1] = 1;
        for(int i = 2; i <= n; i ++  ){
            sum[i] = (sum[i-1]+sum[i-2])%1000000007;
        }
        return sum[n];
    }
};
```