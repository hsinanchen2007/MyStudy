### 解题思路
和循环队列类似，唯一不同的是在队头插入数据时，先移动head指针，再赋值。

### 代码

```python
class MyCircularDeque(object):

    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        :type k: int
        """
        self.n = k+1
        self.arr = [0] * self.n
        self.head = 0
        self.tail = 0

    def insertFront(self, value):
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.head == (self.tail+1) % self.n: 
            return False
        self.head = (self.head - 1 + self.n) % self.n
        self.arr[self.head] = value
        return True

    def insertLast(self, value):
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.head == (self.tail+1) % self.n: 
            return False
        self.arr[self.tail] = value
        self.tail = (self.tail + 1) % self.n
        return True

    def deleteFront(self):
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        if self.head == self.tail: 
            return False
        self.head  = (self.head + 1) % self.n
        return True

    def deleteLast(self):
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        if self.head == self.tail: 
            return False
        self.tail = (self.tail - 1 + self.n) % self.n
        return True

    def getFront(self):
        """
        Get the front item from the deque.
        :rtype: int
        """
        if self.head == self.tail: 
            return -1
        return self.arr[self.head]

    def getRear(self):
        """
        Get the last item from the deque.
        :rtype: int
        """
        if self.head == self.tail: 
            return -1
        return self.arr[(self.tail - 1 + self.n)%self.n]
        

    def isEmpty(self):
        """
        Checks whether the circular deque is empty or not.
        :rtype: bool
        """
        if self.head == self.tail: 
            return True
        return False

    def isFull(self):
        """
        Checks whether the circular deque is full or not.
        :rtype: bool
        """
        if self.head == (self.tail + 1)%self.n: 
            return True
        return False


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
```