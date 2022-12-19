### 解题思路
利用数值存储字符对应的数字
按位遍历（自左至右），每遍历一位计算ans = ans * 26 + num

### 代码

```python3
class Solution:
    def titleToNumber(self, s: str) -> int:
        dic = {}
        for i in range(26):
            dic[chr(ord('A')+i)]=i+1
        n = len(s)
        ans = 0
        for i in range(n):
            num = dic[s[i]]
            ans = ans*26 + num
        return ans

```