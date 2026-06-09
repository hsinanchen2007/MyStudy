### Description 

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

`MyCircularQueue(k)`: Constructor, set the size of the queue to be k.
`Front`: Get the front item from the queue. If the queue is empty, return -1.
`Rear`: Get the last item from the queue. If the queue is empty, return -1.
`enQueue(value)`: Insert an element into the circular queue. Return true if the operation is successful.
`deQueue()`: Delete an element from the circular queue. Return true if the operation is successful.
`isEmpty()`: Checks whether the circular queue is empty or not.
`isFull()`: Checks whether the circular queue is full or not.
 

Example:
```
MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false, the queue is full
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4
```
Note:

All values will be in the range of [0, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in Queue library.


[https://leetcode-cn.com/problems/design-circular-queue](https://leetcode-cn.com/problems/design-circular-queue)

### First thought
1. first we need to list all the interface for a queue
    * `Front`: 
    * `Rear`: 
    * `enQueue(value)`
    * `deQueue()`
    * `isEmpty()`
    * `isFull()`

2. then we need to figure out we use a list or array to implement it.
3. then we need to think about some import conditions:
* when is full?
* when is empty?
* how to move head and tail?

--------------



### Solution1 -- size tracking

#### Key Point

| operation | condition |
| --- | --- |
|Full | count==size |
|empty  | count==0 |
| dequeue | head = (head+1)%size |
| enqueue | tail = (tail+1)%size |
| front  | data[(head+1)%size]  |
| rear | data[(tail-1)%size] |

#### code
```python
class MyCircularQueue(object):
    
    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        :type k: int
        """
        self.size = k
        self.data = [None]*self.size
        self.head = self.tail = 0
        self.n = 0

    def enQueue(self, value):
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False

        self.data[self.tail]=value
        self.tail = (self.tail + 1) % self.size; 
        self.n  += 1 
        
        return True
        

    def deQueue(self):
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        :rtype: bool
        """
        if self.isEmpty():
            return False
            

        self.head = (self.head+1)% self.size
        self.n -=1

        return True
        

    def Front(self):
        """
        Get the front item from the queue.
        :rtype: int
        """
        if self.isEmpty():
            return -1
        else:
            return self.data[self.head]
        

    def Rear(self):
        """
        Get the last item from the queue.
        :rtype: int
        """
        if self.isEmpty():
            return -1
        else:
            return self.data[(self.tail-1)%self.size]
        

    def isEmpty(self):
        """
        Checks whether the circular queue is empty or not.
        :rtype: bool
        """
        return self.n == 0

    def isFull(self):
        """
        Checks whether the circular queue is full or not.
        :rtype: bool
        """
        return self.n == self.size

```


### Solution2 -- resever one

#### Key Point

| operation | condition |
| --- | --- |
|Full |((tail + 1) % size) == head|
|empty  | head == tail |
| dequeue | head = (head+1)%size |
| enqueue | tail = (tail+1)%size |
| front  | data[(head+1)%size]  |
| rear | data[(tail-1)%size] |

this implementation will waste a cell beacuse if you want to use head == tail to be the empty condition. then it cannot be full condition at the same time. so the full condition should be `(tail + 1) % size) == head` this will lead to a cell waste.

**image when you fill the second last cell and tail moves forward to the last cell. the condition is already reached. so the last one can not be fill when next round you check if there is a empty cell**

#### code
```python
class MyCircularQueue(object):
    
    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        :type k: int
        """
        self.size = k+1
        self.data = [None]*self.size
        self.head = self.tail = 0
        

    def enQueue(self, value):
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False
        
        self.data[self.tail]=value
        self.tail = (self.tail + 1) % self.size; 
        return True
        

    def deQueue(self):
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        :rtype: bool
        """
        if self.isEmpty():
            return False
        
        self.head = (self.head+1)% self.size
        
        return True
        

    def Front(self):
        """
        Get the front item from the queue.
        :rtype: int
        """
        if self.isEmpty():
            return -1
        else:
            return self.data[self.head]
        

    def Rear(self):
        """
        Get the last item from the queue.
        :rtype: int
        """
        if self.isEmpty():
            return -1
        else:
            return self.data[(self.tail-1)%self.size]
        

    def isEmpty(self):
        """
        Checks whether the circular queue is empty or not.
        :rtype: bool
        """
        return self.head == self.tail

    def isFull(self):
        """
        Checks whether the circular queue is full or not.
        :rtype: bool
        """
        return ((self.tail + 1) % self.size) == self.head

```




### Reference 

1. [https://leetcode-cn.com/problems/design-circular-queue/solution/she-ji-xun-huan-dui-lie-by-leetcode/](https://leetcode-cn.com/problems/design-circular-queue/solution/she-ji-xun-huan-dui-lie-by-leetcode/)
