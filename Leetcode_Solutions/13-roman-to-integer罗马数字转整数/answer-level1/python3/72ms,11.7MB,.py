### 解题思路
借用一个大佬的方法，举例：IV是4，那就是5-1也就是-1+5。从左至右遍历字符串，每一个字符判断其在roma字典中的值是不是小于下一个字符，如果是那就减去该字符，如果不是就加上该字符
(第一次写，如有错误还请大佬指正)
### 代码

```python
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        s.upper()
        roma = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        ans=0
        for i in range(len(s)):
            if i < len(s)-1 and roma[s[i]] < roma[s[i+1]]:
                ans -= roma[s[i]]
            else:
                ans += roma[s[i]]
        return ans
```