### 解题思路
递归的思路，分别用left，right表示剩余左括号和剩余右括号的数量，
有效括号的组合条件是剩余左括号不能多余右括号

### 代码

```python
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        self.combinations("", res, n, n)
        return res

    def combinations(self, temp, res, left, right):
        if left < 0 or right < 0:
            return
        if left > right:
            return
        if left == 0 and right == 0:
            res.append(temp)
        self.combinations(temp+'(', res, left-1, right)
        self.combinations(temp+')', res, left, right-1)
```