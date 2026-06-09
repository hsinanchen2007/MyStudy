### 解题思路
抓住三个关键点
1. 等差数组至少要3个元素，所以循环是从i=2开始的
2. dp[i]表示以A[i]结尾的等差数列的个数，dp[i] = dp[i-1]+1
3. 所有等差数列的个数即为sum(dp)
4. 显而易见所以等差数列的前2个元素的dp=0，所以dp所有值初始化为0
![捕获.PNG](https://pic.leetcode-cn.com/5d688e01ef4d94bc796bd36081752842700feae2139c59ec19d52b47326f091a-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```python
class Solution:
    # 等差数组至少要3个元素
    # dp[i]表示以A[i]结尾的等差数列的个数
    # dp[i] = dp[i-1]+1
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        n = len(A)
        if n < 3:
            return 0
        dp = [0 for _ in range(n)]
        sum_ans = 0
        for i in range(2,n):
            if A[i]-A[i-1] == A[i-1]-A[i-2]:
                dp[i] = dp[i-1] + 1
                sum_ans += dp[i]
        return sum_ans
```