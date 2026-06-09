### 解题思路
此处撰写解题思路

### 代码

```python3
class MyCircularQueue:

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        self.k = k
        self.q = [0 for _ in range(self.k + 1)]
        self.head, self.tail = 0, 0

    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        if self.isFull():return False
        self.q[self.tail] = value
        self.tail = (self.tail + 1) % (self.k + 1)
        return True

    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if self.isEmpty():return False
        self.head = (self.head + 1) % (self.k + 1)
        return True

    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        if self.isEmpty():return -1
        return self.q[self.head]
        
    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        if self.isEmpty():return -1
        return self.q[self.tail - 1 if self.tail > 0 else self.k]
        
    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        if self.head == self.tail: return True
        return False
        

    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        if (self.tail + 1) % (self.k + 1) == self.head: return True
        return False

# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
```