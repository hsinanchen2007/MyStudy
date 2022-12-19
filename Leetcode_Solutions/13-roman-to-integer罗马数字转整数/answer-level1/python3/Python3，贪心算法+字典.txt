### 解题思路
先把字符串最开始2个字符切片
如果能在字典里找到数值，切出来累加

如果最开始2个切出来匹配不上，
就切一个出来累加
### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        dic = {'M':1000,'CM':900,'D':500,'CD':400,'C':100,'XC':90,
        'L':50,'XL':40,'X':10,'IX':9,'V':5,'IV':4,'I':1}
        acc = 0
        while s != '':
            if s[:2] in dic:
                acc += dic[s[:2]]
                s = s[2:]
            else:
                acc += dic[s[0]]
                s = s[1:]
        return acc

```