### 解题思路
RE+=j-i是标准的可以省略i++的方法

### 代码

```python3
class Solution:
    def triangleNumber(self, s: List[int]) -> int:
        s.sort()
        RE=0
        for k in range(len(s)):
            i,j=0,k-1
            while i<j:
                if s[i]+s[j]>s[k]:
                    RE+=j-i
                    j-=1
                else:
                    i+=1
        return RE
```