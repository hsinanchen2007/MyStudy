### 解题思路
原数组两个元素的最大差等于求差数组的最大子序和
原数组：[a1,a2,a3,a4.....]
求差数组：d1=a2-a1,d2=a3-a2,d3=a4-a3,d4=a5-a4
求差数组的最大子序和(该题需结果大于0):
    dp1=max(0,d1)
    dp2=max(0,dp1+d2)
    ......
    dp(i) = max(0, dp(i-1)+di)
dp(i)为从d1到di的最大子序和，若dp(i-1)小于0，即在di大于0的情况下，dp(i)一定就是di，后续dp(i+1)也相当于dp(i+1)=di+d(i+1)。
### 代码

```python3
#原数组两个元素的最大差等于求差数组的最大子序和！！！
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0: return 0
        ans = 0; temp = 0
        for i in range(1, len(prices)):
            temp = max(0, temp+prices[i]-prices[i-1])
            ans = max(ans, temp)
        return ans

```