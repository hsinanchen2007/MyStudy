### 解题思路
泛型递归的解法

### 代码

```python
class Solution(object):
    def __init__(self):
        self.list_str = []

    def generateParenthesis(self, n):
        self.__generate_Parent(0, 0, n, "")
        return self.list_str

    def __generate_Parent(self, left, right, n, s):
        if left == n and right == n:
            return self.list_str.append(s)
        if left < n:
            self.__generate_Parent(left + 1, right, n, s + "(")
        if left > right:
            self.__generate_Parent(left, right + 1, n, s + ")")
```