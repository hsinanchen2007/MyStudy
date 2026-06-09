### 解题思路
法一：就是纯条件判断解法
法二：正则表达式匹配，用findall或者match

### 代码

```python
class Solution:
    def strToInt(self, str: str) -> int:
        # 法一
        start = 0
        end = 0
        result = ''
        symbol = ''
        max_ = 1<<31-1
        min_ = 1>>31
        includezero = True
        firstblank = 0
        str = str.strip()
        if str == '':
            return 0
        if str[0] == '+':
            symbol = 'plus'
            start += 1
            end += 1
        elif str[0] == '-':
            symbol = 'minus'
            start += 1
            end += 1
        elif ord(str[0]) < 48 or ord(str[0]) > 57:
            return 0
        for i in range(start,len(str)):
            if ord(str[i])== 48 and includezero:
                continue
            if ord(str[i]) >= 48 and ord(str[i]) <= 57:
                includezero = False
                result += str[i]
                end += 1
            else:
                break
        result = int(result) if result != '' else 0
        if symbol == 'plus' and result > (1<<31)-1:
            return (1<<31)-1
        elif symbol == 'plus':
            return result
        if symbol == 'minus' and result*-1 < -(1<<31):
            return -(1<<31)
        elif symbol == 'minus':
            return result*-1
        if symbol == '':
            if result < -(1<<31):
                return -(1<<31)
            if result > (1<<31)-1:
                return (1<<31)-1
            return result




        # 法二
        # int 可以直接去掉0
        import re
        max_ = (1<<31)-1
        min_ = -(1<<31)
        try:
            result = int(re.match('[\+\-]?\d+',str.strip()).group(0))
        except:
            return 0
        return max(min(result,max_),min_)
        
        
        
```