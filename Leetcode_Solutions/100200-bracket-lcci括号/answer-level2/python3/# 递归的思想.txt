### 解题思路
l,r分别表示结果字符串中左右括号的数量。如果l==r==n，即字符串中左右括号的数量都为n，则改字符串为合法字符串，输出。其他分为两种情况：1）什么时候添加'(' ？ 已有的字符串满足左右括号相等，并且左括号数l<n, 则添加'(' ; 2)什么时候添加')' ? 右括号数r<左括号数l。即逐个添加左括号和右括号。

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def f(l, r, s):
            if l == r == n:
                res.append(s)
            if l < n: 
                f(l+1, r, s+'(')
            if r < l:
                f(l, r+1, s+')')
        f(0, 0, '')
        return res
```