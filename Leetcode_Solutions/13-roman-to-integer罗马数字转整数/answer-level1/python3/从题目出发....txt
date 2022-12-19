### 解题思路
因为9、4是从10、5减1得到了，IV的意思就是V-I，所以从后往前读，正常的I不会再V前，先读到V后读到I一定是相减，剩下的都是相加，十位百位千位的道理都是一样的，所以只需要从后往前遍历一边字符串s就得到最后的答案了

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        roma = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000} 
        myLen, now = len(s), 0
        res = 0
        for i in range(myLen):
            if roma[s[myLen-i-1]]>=now:
                res += roma[s[myLen-i-1]]
                now = roma[s[myLen-i-1]]
            else:
                res -= roma[s[myLen-i-1]]
        return res
```