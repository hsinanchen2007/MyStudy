### 解题思路
循环队列需要队front和rear做求模运算

### 代码

```python3
class MyCircularQueue:

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        self.Max = k # 队列最大容量
        self.length = 0 # 队列实际长度
        self.front = 0 # front下标
        self.rear = 0  # rear下标
        self.arr = [0 for i in range(self.Max)]  #创建数组存放队列数据

    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        if self.isFull():
            return False
        else:
            self.length += 1
            self.arr[self.rear] = value
            self.rear = (self.rear + 1 ) % self.Max # rear 后移一位
            return True

    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        else:
            self.length -= 1 # 删除一个元素，长度变短1
            self.front = (self.front + 1)% self.Max  # 从队列前端删除一个数据，然后第二个成为新的头
            return True
        
    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        if self.isEmpty():
            return -1
        else:
            return self.arr[self.front]
        
    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        if self.isEmpty():
            return -1
        else:
            return self.arr[self.rear - 1]

    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        if self.length == 0:
            return True
        else:
            return False
        
    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        if self.length == self.Max:
            return True
        else:
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