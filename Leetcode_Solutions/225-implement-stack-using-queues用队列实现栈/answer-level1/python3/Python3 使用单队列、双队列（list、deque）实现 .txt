### 解题思路
使用单队列（list）实现
方法一：使用一个队列，队列添加元素后，反转前n-1个元素，栈顶元素始终保留在队首
![截屏2020-03-01下午12.57.34.png](https://pic.leetcode-cn.com/235b588ff825ce0d2d9c5d7691e7dff5fce4be806d8b2581aee1978a3ef9f729-%E6%88%AA%E5%B1%8F2020-03-01%E4%B8%8B%E5%8D%8812.57.34.png)

### 代码

```
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = []

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q.append(x)
        q_length = len(self.q)
        while q_length > 1:
            self.q.append(self.q.pop(0)) #反转前n-1个元素，栈顶元素始终保留在队首
            q_length -= 1

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.q.pop(0)

    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q[0]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not bool(self.q)





# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()

```
方法二 使用双队列（deque）实现
![截屏2020-03-01下午12.47.15.png](https://pic.leetcode-cn.com/25fe53067fc48f3f9a93d6cd28d410d9a24d44042b5f23c6201530e642e7e040-%E6%88%AA%E5%B1%8F2020-03-01%E4%B8%8B%E5%8D%8812.47.15.png)

```
from collections import deque
class MyStack:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = deque()
        self.help = deque()
    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.data.append(x)
    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        while len(self.data) > 1:
            self.help.append(self.data.popleft())
        tmp = self.data.popleft()        
        self.help,self.data = self.data,self.help
        return tmp
    def top(self) -> int:
        """
        Get the top element.
        """
        while len(self.data) != 1:
            self.help.append(self.data.popleft())
        tmp = self.data.popleft()
        self.help.append(tmp)
        self.help,self.data = self.data,self.help
        return tmp
    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not bool(self.data)

```
更多内容：
[欢迎关注简书](https://www.jianshu.com/p/5e10004e53bc)