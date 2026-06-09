### 解题思路
此处撰写解题思路
- 就是一个相当于两个桶来回倒。
### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.MyStackfont = []
        self.MyStackbehind = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.MyStackfont.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.MyStackfont)!=0:
            self.MyStackbehind.append(self.MyStackfont.pop(0))    
        return self.MyStackbehind.pop()

    def top(self) -> int:
        """
        Get the top element.
        """
        while len(self.MyStackfont)!=0:
            self.MyStackbehind.append(self.MyStackfont.pop(0))   
        return self.MyStackbehind[-1]

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if len(self.MyStackfont) ==0 and len(self.MyStackbehind)==0:
            return True
        return False


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```