### 解题思路
同习题 [面试题38. 字符串的排列](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/gelthin-di-gui-jie-quan-pai-lie-hui-su-by-gelthin/)


#### 缩进错误导致一直输出 null, 太坑了。



### 代码

```python3
class Solution:
    def permutation(self, S: str) -> List[str]:
        def dfs(tmp):
            if len(tmp) == len(S):
                res.append(tmp)
                return
            for i in range(len(S)):
                if i>0 and S[i-1] == S[i] and not visited[i-1]:
                    continue
                elif not visited[i]:
                    visited[i] = True
                    dfs(tmp+S[i])
                    visited[i] = False
            
        S = sorted(list(S))
        res = []
        visited = [False]*len(S)
        dfs("")
        return res  # 缩进错了，导致一直输出 null, 太坑了
```