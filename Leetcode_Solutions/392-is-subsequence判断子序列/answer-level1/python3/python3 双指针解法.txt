### 解题思路
使用i，j两个指针分别指向s和t，进行扫描
时间复杂度：O(len(t))
空间复杂度：O(1)

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i,j=0,0
        while i < len(s) and j < len(t):
            if s[i]==t[j]:
                i+=1
                j+=1
            else:
                j+=1
        return i==len(s)
```