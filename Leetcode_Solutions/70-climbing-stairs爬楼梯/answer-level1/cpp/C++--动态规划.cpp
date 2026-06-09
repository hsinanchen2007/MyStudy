### 解题思路
此处撰写解题思路
![03.jpg](https://pic.leetcode-cn.com/35c6b229a3483ad71cae047b6ac1325aaa7390aae699b48ed30996c11d8ccb9e-03.jpg)
### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int *dp=(int *)malloc(sizeof(int)*(n+1));
        dp[0]=1;
        dp[1]=2;
        int i;
        for(i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};
```