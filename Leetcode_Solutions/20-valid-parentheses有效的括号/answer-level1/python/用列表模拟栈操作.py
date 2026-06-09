### 解题思路
此处撰写解题思路
1.用列表模拟栈操作，遇到左括号入栈。遇到有括号，栈中为空或者不是对应的右括号则返回False
2.遍历完字符串后，如果栈中非空，则说明有左括号没有对应的右括号，返回False。否则返回True。

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        stock, count = [], 0
        length = len(s)
        for i in range(0, length, 1):
            if s[i] == '(' or s[i] == '[' or s[i] == '{':
                stock.append(s[i])
                count += 1
            elif s[i] == ')' or s[i] == ']' or s[i] == '}':
                if count == 0:
                    return False
                if (stock[count - 1] == '(' and s[i] == ')') \
                    or (stock[count - 1] == '[' and s[i] == ']') \
                    or (stock[count - 1] == '{' and s[i] == '}'):
                    stock = stock[:-1]
                    count -= 1
                else:
                    return False
        if count == 0:
            return True
        return False
```