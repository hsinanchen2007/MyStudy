### 解题思路
想法很简单：
有两个队列 L1, L2, 每次保持一个队列为空。当要入元素时，入到非空的队列中；当要出元素时，设 L1 非空，L2 为空，把 L1 中前 n-1 个元素导入到 L2 中，返回 L1 中剩下的一个元素，n -= 1。  

入元素： O(1)
出元素： O(n)

### 代码

```python3
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.L1 = []
        self.L2 = []
        self.n = 0

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        if self.L2:
            self.L2.append(x)
        else:
            self.L1.append(x)  # 当 L1, L2 都空，放入 L1
        self.n += 1


    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if self.n == 0:
            return None
        if self.L1:
            for _ in range(self.n-1):
                self.L2.append(self.L1.pop(0))
            self.n -= 1
            return self.L1.pop(0)
        else:
            for _ in range(self.n-1):
                self.L1.append(self.L2.pop(0))
            self.n -= 1
            return self.L2.pop(0)


    def top(self) -> int:
        """
        Get the top element.
        """
        if self.n == 0:
            return None
        if self.L1:
            for _ in range(self.n-1):
                self.L2.append(self.L1.pop(0))
            result = self.L1.pop(0)
            self.L2.append(result)  # list append 元素到底是什么？
            return result
        else:
            for _ in range(self.n-1):
                self.L1.append(self.L2.pop(0))
            result = self.L2.pop(0)
            self.L1.append(result)
            return result


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.n == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```