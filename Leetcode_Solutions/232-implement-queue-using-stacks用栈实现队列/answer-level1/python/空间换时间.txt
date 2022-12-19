### 解题思路
此处撰写解题思路

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
        #怎么实现
        if not self.empty():
            temp=[]
            for i in range(len(self.queue)-1):
                elem=self.queue.pop()
                temp.insert(0,elem)
            elem=self.queue.pop()
            self.queue=temp
            return elem

    def peek(self) -> int:
        """
        Get the front element.
        """
        temp=[]
        if not self.empty():
            for i in range(len(self.queue)):
                elem=self.queue.pop()
                temp.insert(0,elem)
            self.queue=temp
            return elem
        

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not self.queue


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```