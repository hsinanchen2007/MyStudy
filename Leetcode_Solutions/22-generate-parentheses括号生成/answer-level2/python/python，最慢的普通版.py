### 解题思路
能组成有效括号的唯一要求就是左括号的数量**时刻**不得少于右括号数量。
基于此，一个递归就出来：
- 定义递归函数，传参当前形成括号字符串，左括号剩余数、右括号剩余数
- 如果左右括号都用完了，结果加入到总结果列表中
- 如果左括号还有，那么先用它一个左括号，再递归试试
- 如果右括号数量比左括号多，那么右括号也可以先用它一个，再递归试试

如此，就完成了。

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def helper(s, l, r):
            if not l and not r:
                res.append(s)
            if 0 <= l:
                helper(s+'(', l-1, r)
            if r > l:
                helper(s+')', l, r-1)
        helper('', n, n)
        return res
```
欢迎关注个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)