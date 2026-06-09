### 解题思路
时间复杂度：排序需要O(nlog(n))，双指针需要O(n)，所以综合来看需要O(nlog(n))
空间复杂度：O(1)

### 代码

```python3
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        i=0
        j=0
        while i < len(g) and j < len(s):
            if s[j] >= g[i]:
                i+=1
            j+=1
        return i
            
```