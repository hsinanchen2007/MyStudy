### 解题思路
除了一个常规列表实现栈的操作外，再开一个辅助栈用于保存当前的最小信息：
- 入栈操作：当辅助栈为空或者新元素小于等于辅助栈顶元素时，辅助栈入栈；否则无视
- 出栈操作：当常规栈中待出栈的元素等于辅助栈顶元素时，辅助栈出栈一个元素，代表当前的最小值出队或者次数减1
- 栈顶操作：仅需从常规栈顶取元素即可
- 最小值操作：因为辅助栈中维护的都是当前状态下的最小值，所以从辅助栈顶取元素即可
- 另外，利用and的短路特性实现对两个栈非空判断，确保操作的稳健性。

### 结果
![image.png](https://pic.leetcode-cn.com/b18a822f9034de956622fde1e84bbee19ba5c6b7653d7d5d35b0e90981c247cf-image.png)

### 代码

```python3
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.mins = []

    def push(self, x: int) -> None:
        self.stack.append(x)
        if not self.mins or x <= self.mins[-1]:
            self.mins.append(x)

    def pop(self) -> None:
        if not self.stack:
            return
        x = self.stack.pop()
        if self.mins and self.mins[-1]==x:
            self.mins.pop()

    def top(self) -> int:
        return self.stack and self.stack[-1]

    def min(self) -> int:
        return self.mins and self.mins[-1]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()
```