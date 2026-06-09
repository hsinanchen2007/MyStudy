### 解题思路
![image.png](https://pic.leetcode-cn.com/e07041b210238469a3558099c1c6e338c632247261da3ef912b86308d80d548b-image.png)
从后向前做dp就可以了。
dp[i]标识[i, ..., n]时先手获得的最大得分，那么sum - dp[i]就是后手获得的最大得分了。
边界条件是dp[n] = stoneValue[n]
转移方程是
a1 = stonevalue[i] + sum[i+1:] - dp[i+1]
a2 = sum(stonevalue[i:i+2]) + sum[i+2:] - dp[i+2]
a2 = sum(stonevalue[i:i+3]) + sum[i+3:n] - dp[i+3]
dp[i] = max([a1, a2, a3])

注意处理时候的边界条件就行了。代码如下
### 代码

```python3
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        dp = [-5e7]*len(stoneValue)
        dp [-1] = stoneValue[-1]
        sum_sto = [0]*len(stoneValue)
        sum_sto[-1] = stoneValue[-1]
        for i in range(len(stoneValue)-2, -1, -1):
            sum_sto[i] = sum_sto[i+1] + stoneValue[i]
        for i in range(len(dp)-1, -1, -1):
            if i == len(dp) -1:
                continue;
            tmp = []
            if len(dp) - i>1:
                tmp_v = stoneValue[i] + sum_sto[i+1] - dp[i+1]
                tmp.append(tmp_v)
            if len(dp) - i == 2:
                tmp_v = sum(stoneValue[i:i+2])
                tmp.append(tmp_v)
            if len(dp) - i>2:
                tmp_v = sum(stoneValue[i:i+2]) + sum_sto[i+2] - dp[i+2]
                tmp.append(tmp_v)
            if len(dp) -i == 3:
                tmp_v = sum(stoneValue[i:i+3])
                tmp.append(tmp_v)
            if len(dp) - i>3:
                tmp_v = sum(stoneValue[i:i+3]) + sum_sto[i+3] - dp[i+3]
                tmp.append(tmp_v)
            dp[i] = max(tmp)
        
        if dp[0] > sum_sto[0] - dp[0]:
            return 'Alice'
        elif dp[0] == sum_sto[0] - dp[0]:
            return 'Tie'
        else:
            return 'Bob'
```