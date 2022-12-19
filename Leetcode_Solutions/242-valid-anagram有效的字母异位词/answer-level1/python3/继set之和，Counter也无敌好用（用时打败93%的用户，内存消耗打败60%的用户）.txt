### 解题思路
直接调用Counter统计两个字符串中字符的个数,然后比较

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        '''if len(s) != len(t):
            return False
        num1 = []
        num2 = []
        for i in range(0,len(s)):
            num1.append(ord(s[i]))
            num2.append(ord(t[i]))
        return num1.sort()==num2.sort()'''
        from collections import Counter
        return Counter(s)==Counter(t)
```