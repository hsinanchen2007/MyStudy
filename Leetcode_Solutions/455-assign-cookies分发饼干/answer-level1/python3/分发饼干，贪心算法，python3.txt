### 解题思路
总是把最小的饼干喂食量最小的小朋友

### 代码

```python3
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        res = 0
        g.sort()
        s.sort()
        
        g_length = len(g)
        s_length = len(s)
        
        i = 0
        j = 0
        while i < g_length and j < s_length:
            if g[i] <= s[j]:
                res += 1
                i += 1
                j += 1
            else:
                j += 1
                
        return res
```