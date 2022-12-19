![image.png](https://pic.leetcode-cn.com/a0872222e880a88b38f189f2989f0ebeed6c61f7048e5e2dfe688718d078a228-image.png)


```
'''
动态规划
dp(i, 0) 表示以i位置结尾，不能进行删除操作情况下最大的元素总和
dp(i, 1) 表示以i位置结尾，最多进行一次删除操作情况下最大的元素总和

dp(i, 0) = max {
    arr[i],
    arr[i] + dp(i-1, 0)
}

dp(i, 1) = max {
    dp(i-1, 0)      # 删除操作用在最后一个元素上
    dp(i-1, 1) + arr[i]
}


'''

from typing import List
class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        n = len(arr)
        dp = [[0, 0] for _ in range(n)]

        dp[0][0], dp[0][1] = arr[0], arr[0]
        ans = max(dp[0][0], dp[0][1])
        for i in range(1, n):
            dp[i][0] = max(arr[i], arr[i] + dp[i-1][0])
            dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i])
            ans = max(ans, dp[i][0], dp[i][1])
        return ans
```
