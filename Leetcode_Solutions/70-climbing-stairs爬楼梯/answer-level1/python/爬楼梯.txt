### 解题思路
采用动态规划，最后一层台阶有两种方式到达，分别是下一层上一阶或下下层上两阶，迭代。

### 代码

```cpp []
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int sum=0;
        vector<int> dp={1,2};    //注意此处要采用动态数组，因为n不可控，vector输入值可用.push_back(x)逐个输入，也可用.insert(下标,x)指定位置插入
        for(int i=2;i<n;i++)
        {
            int temp=dp[i-1]+dp[i-2];
            dp.push_back(temp);
        }
        sum=dp[n-1];
        return sum;
    }
};
```
```python []
class Solution:
    def climbStairs(self, n: int) -> int:
        if n<=2:
            return n
        dp1,dp2=1,2
        for i in range(3,n+1):
            dp1,dp2=dp2,dp1+dp2
        return dp2
```
