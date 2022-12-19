### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def generate(prefix, left, right, parens=[]):
            if right == 0:   parens.append(prefix)  # 右括号用完了左括号一定也用完了
            if left > 0:     generate(prefix + '(', left-1, right) #左括号还有的时候，就递归调用
            if right > left: generate(prefix + ')', left, right-1)
            return parens
        return generate('', n, n)
```