![image.png](https://pic.leetcode-cn.com/4fb04d41fb07be18a11d7a8baa7b7351aea10b39db424b6a485b22859e43bcea-image.png)


```
'''
前缀和思想，利用异或的结合性进行dp递推
[a, b]区段异或和等于[0, b]区段异或和 ^ [0, a-1]区段异或和
'''

from typing import List
class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n = len(arr)
        dp = [0 for _ in range(n)]
        dp[0] = arr[0]
        for i in range(1, n):
            dp[i] = dp[i-1] ^ arr[i]

        return [dp[q[1]] if q[0] == 0 else dp[q[1]] ^ dp[q[0]-1] for q in queries]
```
