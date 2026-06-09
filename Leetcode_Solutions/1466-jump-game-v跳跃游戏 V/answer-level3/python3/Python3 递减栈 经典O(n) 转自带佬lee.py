### 解题思路
 单调栈 
转自leetcode的带佬lee 
经典O(n)
经典双100% 
分享用于交流学习

### 代码

```python3
class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:

        # 单调栈 O（n）
        # 递减栈  -》 找到两边都比栈顶元素（index）大的
        n = len(arr)
        dp = [1] * (n + 1)
        stack = []
        for i, a in enumerate(arr + [float("inf")]):
            while stack and arr[stack[-1]] < a:
                L = [stack.pop()]
                while stack and arr[stack[-1]] == arr[L[0]]:
                    L.append(stack.pop())
                for j in L:
                    if i - j <= d:
                        dp[i] = max(dp[i], dp[j] + 1)
                    if stack and j - stack[-1] <= d:
                        dp[stack[-1]] = max(dp[stack[-1]], dp[j] + 1)
            stack.append(i)
        return max(dp[:-1])
```