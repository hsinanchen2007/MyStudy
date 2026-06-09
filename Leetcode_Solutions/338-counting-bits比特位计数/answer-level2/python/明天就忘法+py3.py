### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countBits(self, num: int) -> List[int]:
        dp=[0]*(num+1)
        for i in range(1,num+1):
            #n&(n-1)去掉从右边到左边的第一位为1 变为0
            #3(11)=2(10)+1(1)则dp[3]=dp[3&(3-1)]+1=dp[2]+1
            dp[i]=dp[i&(i-1)]+1
        return dp
```