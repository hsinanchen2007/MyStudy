### 解题思路
1、初始化栈
2、入栈append()，出栈pop()，获取栈顶index=-1，获取最小值可将stack排序后返回第0个元素。

### 代码

```python3
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []


    def push(self, x: int) -> None:
        self.stack.append(x)


    def pop(self) -> None:
        self.stack.pop()


    def top(self) -> int:
        return self.stack[-1]


    def getMin(self) -> int:
        new_list = sorted(self.stack)
        return new_list[0]



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```