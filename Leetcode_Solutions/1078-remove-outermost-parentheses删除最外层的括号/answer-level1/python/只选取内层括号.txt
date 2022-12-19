### 解题思路
（入栈，）出栈，需要注意的是，出战的时候，如果栈为空，说明遇到了最外层括号，那么直接把最外层 括号里面的切片加入到答案字符串即可。

### 代码

```python3
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        stk = []
        tmp_str = ''
        ans = ''
        index = 0
        for i, s in enumerate(S):
            if s=='(':
                stk.append('(')
            elif s==')' and stk:
                stk.pop()
                if not stk:
                    ans += S[index+1:i]
                    index = i+1
        return ans
            


```