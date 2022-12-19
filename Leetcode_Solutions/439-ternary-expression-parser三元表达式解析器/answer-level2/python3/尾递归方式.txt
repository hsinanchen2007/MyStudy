### 解题思路
![image.png](https://pic.leetcode-cn.com/252221b9e842a21d4bdb7c7a87aea5fee2642109cbfca4f8ce2d516898f928e3-image.png)

- 尾递归方式
对每个判断条件，找出分界点，分界点通过`?`和`:`的数量匹配进行查找
直到`expression`的长度为1的时候，结束，也就是找到了返回值

### 代码

```python
class Solution:
    def parseTernary(self, expression: str) -> str:
        if len(expression) == 1:
            return expression
        condition = expression[0]
        position = 2
        left_count = 1
        while position < len(expression):
            if expression[position] == "?":
                left_count += 1
            elif expression[position] == ":":
                left_count -= 1
            if left_count == 0:
                break
            position += 1
        if condition == "T":
            return self.parseTernary(expression[2:position])
        else:
            return self.parseTernary(expression[position + 1:])

```