使用栈记录`(`出现的位置, 开始认为所有`(`都合法, 当出现`)`,如果栈内有元素,说明`)`合法, 出栈.
如果没有, 则舍去`)`, 最后, 栈内剩余元素为不合法的`(`,替换成空字符即可

```python
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        res = [''] * len(s)
        for idx, val in enumerate(s):
            if val == '(':
                stack.append([idx, '('])
                res[idx] = '('
            elif val == ')':
                if stack:
                    stack.pop()
                    res[idx] = ')'
            else:
                res[idx] = val
        for tmp in stack:
            res[tmp[0]] = ''
        return ''.join(res)
```