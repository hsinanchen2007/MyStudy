### 解题思路
1、维护一个栈，遇到左括号就入栈，遇到右括号就弹出栈顶匹配，如果匹配则扔掉；如果不匹配则返回False；
2、为了得到左括号和右括号的关系，可以提前建立字典映射，方便根据右括号查询对应的左括号；
3、处理边界1：只有右括号，栈中还没有左括号；
4、python的list的pop()才是弹出栈顶，不能写成pop(0)，那是在模拟队列；
5、如果遍历完毕，栈中还有内容，则说明不匹配，返回False;

### 代码

```python3
class Solution:
    """
    https://leetcode-cn.com/problems/valid-parentheses/
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

    有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
    注意空字符串可被认为是有效字符串。
    """

    def __init__(self):
        self.bracket_map = {
            ")": "(",
            "}": "{",
            "]": "["
        }

    def isValid(self, s: str) -> bool:
        if not s or len(s) == 0:
            return True

        stack = []
        for item in s:
            # 如果遇到了右括号，就弹出栈顶，如果匹配则扔掉，不匹配则返回false
            if item in self.bracket_map:
                if len(stack) == 0:
                    return False
                top = stack.pop()
                if self.bracket_map[item] != top:
                    return False

            # 如果遇到了左括号，则入栈
            if item in self.bracket_map.values():
                stack.append(item)

        if len(stack) > 0:
            return False

        return True
```