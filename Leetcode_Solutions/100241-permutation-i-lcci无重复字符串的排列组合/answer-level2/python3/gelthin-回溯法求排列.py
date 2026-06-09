### 解题思路
同习题 [面试题38. 字符串的排列](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/gelthin-di-gui-jie-quan-pai-lie-hui-su-by-gelthin/)

### 代码

```python3
class Solution:
    def permutation(self, S: str) -> List[str]:
        def dfs(tmp):
            if len(tmp) == len(S):
                res.append(tmp)
            for i in range(len(S)):
                if not visited[i]:
                    visited[i] = True
                    dfs(tmp+S[i])
                    visited[i] = False
        res = []
        visited = [False]*len(S)
        dfs("")
        return res
```