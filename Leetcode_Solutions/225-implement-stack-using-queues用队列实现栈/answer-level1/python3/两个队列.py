### 解题思路
push 时间复杂度O(1)，pop时间复杂度O(n)，top时间复杂度O(1),empty时间复杂度O(1)

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = []
        self.q2 = []
        self.top_num = None

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q1.append(x)
        self.top_num = x
        


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.q1)>1:
            out = self.q1[0]
            self.q1.remove(out)
            self.q2.append(out)
            self.top_num = out
        if len(self.q1)>0:
            out = self.q1[0]
            self.q1.remove(self.q1[0])
            tmp = self.q2
            self.q2 = self.q1
            self.q1 = tmp
            return out


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.top_num


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.q1)==0
        



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```