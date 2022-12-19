### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/1820e65f775d6fc761d95c48a1111968029715f605108b0739b4dd3249abbfe4-image.png)

### 代码

```python3
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.a = []


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.a.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        b = self.a[0]
        self.a = self.a[1:]
        return b

    def peek(self) -> int:
        """
        Get the front element.
        """
        return  self.a[0]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        if len(self.a) == 0:
            return True
        else:
            return False


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```