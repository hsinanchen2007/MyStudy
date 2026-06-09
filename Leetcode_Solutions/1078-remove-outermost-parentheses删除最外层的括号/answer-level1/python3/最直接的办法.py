判断'(' AND ')' 的数量，相等的时候，则匹配，去掉最外层括号即可

```
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        l_num = 0
        r_num = 0
        sub_s = ''
        total_s = ''
        for s in S:
            if s == '(':
                l_num +=1
                sub_s += s
            else:
                r_num +=1
                sub_s += s
            if l_num == r_num:
                sub_s = sub_s[1:-1]
                total_s += sub_s
                l_num = 0
                r_num = 0
                sub_s = ''
        return total_s
```



