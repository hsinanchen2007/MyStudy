### 解题思路
将罗马数字分成两类：能组合和不能组合，并存放在字典中。
i为索引序号，遍历字符串。若可组合i+=2,不能组合i+=1

ps:发现服务器执行很不稳定。同样的代码跑了三次，时间分别为56ms,36ms,80ms。
### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        table1 = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        table2 = {'IV':4, 'IX':9, 'XL':40, 'XC':90,'CD':400,'CM':900}
        head1 = 'IXC'
        head2 = 'VLDM'

        i, result = 0, 0
        while i < len(s) - 1:
            twoChr = s[i] + s[i + 1]
            if (s[i] in head1) and (twoChr in table2):
                result += table2[twoChr]
                i += 2
            else:
                result += table1[s[i]]
                i += 1

        if i == len(s) - 1:
            result += table1[s[i]]

        return result
```