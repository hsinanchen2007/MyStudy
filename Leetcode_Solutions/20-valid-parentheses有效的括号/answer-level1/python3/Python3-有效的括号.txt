### 解题思路
用Python中的列表初始化一个空栈，列表的末尾作为栈顶。
依次读取给定字符串中的字符:
    如果是左括号:
        入栈
    否则：
        此时判断栈是否为空，栈如果空了就表示右括号多了：
            匹配失败
        否则：
            栈顶元素出栈
            判断出栈元素与此时右括号是否为统一类型左、右括号，不是：
                匹配失败
当字符串中所有字符都读取完毕，此时检查栈是否为空，若栈空了：
    匹配成功
否则，表示左括号多了：
    匹配失败

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        Stack = []
        balanced = True
        index = 0
        while index < len(s) and balanced:
            symbol = s[index]
            if symbol in "([{":
                Stack.append(symbol)
            else:
                if Stack == []:
                    balanced = False
                else:
                    top = Stack.pop()
                    if not self.matches(top, symbol):
                        balanced = False
            index += 1
        if balanced and Stack == []:
            return True
        else:
            return False

    def matches(self,open,close):
            opens = "([{"
            closers = ")]}"
            return opens.index(open) == closers.index(close)

```