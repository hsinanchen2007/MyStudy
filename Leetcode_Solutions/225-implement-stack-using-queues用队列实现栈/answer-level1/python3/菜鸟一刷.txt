### 解题思路
init初始化队列
push入队列
pop出队列
top返回队列顶端元素
empty检查是否为空
### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack=[]


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.stack.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if len(self.stack)>0:
            a=self.stack[-1]
            del self.stack[-1]
            return a 
        return None


    def top(self) -> int:
        """
        Get the top element.
        """
        if len(self.stack)>0:
            return self.stack[-1]
        return None

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.stack)==0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```