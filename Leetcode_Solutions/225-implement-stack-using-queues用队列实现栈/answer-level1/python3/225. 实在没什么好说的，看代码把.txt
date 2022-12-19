### 解题思路
此处撰写解题思路

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []


    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.stack.append(x)


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if not self.stack:
            return None
        else:
            pop =  self.stack[-1]
            del self.stack[-1]
        return pop
        
    def top(self) -> int:
        """
        Get the top element.
        """
        if not self.stack:
            return None
        else:
            top =  self.stack[-1]
        return top



    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if not self.stack:
            return True 
        return False



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```