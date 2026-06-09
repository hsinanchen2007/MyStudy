### 解题思路

### 代码

```python3
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        dp = [[] for _ in range(len(s) + 1)]
        dp[-1] = [[]]
        for i in range(len(s) - 1, -1, -1):
            for j in range(i+1, len(s)+1):
                # 判断自i到j是不是回文，如果是的话，就和dp[j]进行操作
                if s[i:j] == s[i:j][::-1]:
                    for each in dp[j]:
                        dp[i].append([s[i:j]] + each)
        return dp[0]
```