一 分析与设计
(一)循环队列
设计一个循环对列，重点在于在各项操作中维持数据不变式，即维持对象属性之间的正确关系。
（1）构造函数中定义四个属性：
self._len:队列长度
self._elems:用于记录循环队列元素的列表
self._head:队列中第一个元素的下标
self._num:队列中的元素个数
（2）进队列
在队列尾部加入元素，并是self._num加1，以维持对象属性之间的正确关系。
（3）出队列
只是对列中第一个元素下标的指针后移1，同时将self._num减1。
其余操作容易理解，可参看以下代码。
（4）获取队列首元素
若队列为空，即self._num等于0，返回-1；否则，返回索引self._head中的元素
（5）获取队列尾端元素
若对列为空，返回-1；否则，返回索引(self._head + self._num - 1) % self._len中元素，之所以要进行取模操作，是因为该队列为循环对列，存储队列元素的列表最后一个位置的下一个位置为其首位置
（6）队列为空
self._num为0
（7）队列为满
self._num等于self._len
（二）循环双端队列
循环双端队列大致思路如上，只是多个几个操作，现只讲述增加的几个操作
（1）前端插入
队列满，则返回False。
否则将队列首指针前移一位self._head = (self._head - 1 + self._len) % self._len，之所以要进行+self._len后取模的形式，是考虑到self._head为0的情形。
之后，将队列首指针对应元素赋值，并将队列元素数加1。
self._elems[self._head] = value
self._num += 1
（2）尾端删除
若self._num为0，则返回False;否则只需将队列中元素数self._num减一即可。
二 算法实现
循环队列
```python3 []
class MyCircularQueue:

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        self._len = k
        self._elems = [0] * self._len
        self._head = 0
        self._num = 0

    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        if self._num == self._len:
            return False
        else:
            self._elems[(self._head + self._num) % self._len] = value
            self._num += 1
            return True

    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if self._num == 0:
            return False
        else:
            self._head = (self._head + 1) % self._len
            self._num -= 1
            return True

    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        if self._num == 0:
            return -1
        return self._elems[self._head]

    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        if self._num == 0:
            return -1
        return self._elems[(self._head + self._num - 1) % self._len]

    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        return self._num == 0

    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        return self._num == self._len
```
循环双端队列
```python3 []
class MyCircularDeque:

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        """
        self._len = k
        self._elems = [0] * self._len
        self._head = 0
        self._num = 0

    def insertFront(self, value: int) -> bool:
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        """
        if self._num == self._len:
            return False
        self._head = (self._head - 1 + self._len) % self._len
        self._elems[self._head] = value
        self._num += 1
        return True

    def insertLast(self, value: int) -> bool:
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        """
        if self._num == self._len:
            return False
        self._elems[(self._head + self._num) % self._len] = value
        self._num += 1
        return True

    def deleteFront(self) -> bool:
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        """
        if self._num == 0:
            return False
        self._head = (self._head + 1) % self._len
        self._num -= 1
        return True
        
        
    def deleteLast(self) -> bool:
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        """
        if self._num == 0:
            return False
        self._num -= 1
        return True

    def getFront(self) -> int:
        """
        Get the front item from the deque.
        """
        if self._num == 0:
            return -1
        return self._elems[self._head]

    def getRear(self) -> int:
        """
        Get the last item from the deque.
        """
        if self._num == 0:
            return -1
        return self._elems[(self._head + self._num - 1) % self._len]

    def isEmpty(self) -> bool:
        """
        Checks whether the circular deque is empty or not.
        """
        return self._num == 0

    def isFull(self) -> bool:
        """
        Checks whether the circular deque is full or not.
        """
        return self._num == self._len
```
三 复杂度分析
初始化操作中生成初始列表时间复杂度为O(k)，但初始化操作只执行一次，其余操作时间复杂度均为O(1)。
空间复杂度O(k)。


