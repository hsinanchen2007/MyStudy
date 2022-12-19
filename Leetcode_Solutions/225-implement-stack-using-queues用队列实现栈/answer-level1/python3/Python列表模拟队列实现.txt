### 解题思路
使用python中的列表来代表队列，实现栈的存取功能
栈的push()对应列表的append()
栈的pop()对应列表的pop()
列表的两个操作不指定index的情况下默认末尾
### 代码
```python3
class MyStack:

    def __init__(self):
        self.stack = []
        
    def push(self, x: int) -> None:
        return self.stack.append(x)

    def pop(self) -> int:
        return self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def empty(self) -> bool:
        return True if len(self.stack)==0 else False


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```