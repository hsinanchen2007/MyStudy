### 解题思路
用list完全模拟stack，没什么太精彩的算法，就是用stack的基本操作

### 代码

```python3
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue=[]

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.queue.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        buff=[]
        while len(self.queue)>0:
            buff.append(self.queue[-1])
            del self.queue[-1]
        num=buff[-1]
        del buff[-1]
        while len(buff)>0:
            self.queue.append(buff[-1])
            del buff[-1]
        return num

    def peek(self) -> int:
        """
        Get the front element.
        """
        buff=[]
        length=len(self.queue)
        while length>0:
            buff.append(self.queue[length-1])
            length-=1
        return buff[-1]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return True if len(self.queue)==0 else False



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```