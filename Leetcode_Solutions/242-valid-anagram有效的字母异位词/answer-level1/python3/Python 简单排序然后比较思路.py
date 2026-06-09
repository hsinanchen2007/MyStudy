### 解题思路
1、先将字符串转成list进行排序，
2、然后对排序后的字符串进行比较，得到答案
3、此方法的时间复杂度和空间复杂度都高一些，但是能通过

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s = list(s)
        s.sort()
        s = "".join(s)
        t = list(t)
        t.sort()
        t = "".join(t)

        return s==t

       
```