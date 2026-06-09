
使用了python 模拟数组实现，没有使用python list 的pop() 
有几个点：
   - 数组空间要多一位，用来区分队列满了而不是空队列。
   - start指针始终指向队列第一个元素，rear 尾指针始终指向队列最后一个元素的下一位。
   - 因此队列空时添加第一个头部元素，注意要把尾指针右移1位
   - 注意函数的返回要求，getRear 等在队列空时返回-1 而不是False
   - 调用判空函数时，记得带()
   - 调用类成员时，记得加self.

```
class MyCircularDeque(object):

    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        :type k: int
        """
        self.capacity = k+1 #数组多1个位置，用于标记是否满
        self.start = self.rear = 0 #rear 总是指向最后一个元素的下一个位置
        self.queue = [float('inf')] * self.capacity
        
    def insertFront(self, value):
        if self.isFull():    
            return False
        else:
            if self.isEmpty() : #不要写 isEmpty() == 0 
                self.queue[self.start] = value
                self.rear += 1 #空的时候添加第一个元素，尾巴要加1
            else:
                index = (self.start -1 ) % self.capacity
                self.queue[index]  = value
                self.start = index
        return True

    def insertLast(self, value):
        if self.isFull():
            return False
        else:
            self.queue[self.rear]  = value
            self.rear = (self.rear + 1) % self.capacity
        return True

    def deleteFront(self):
        if self.isEmpty():
            return False
        else:   
            self.start  = (self.start + 1) % self.capacity
        return True

    def deleteLast(self):
        if self.isEmpty():
            return False
        else:   
            self.rear  = (self.rear - 1) % self.capacity
            self.queue[self.rear] = float('inf')
        return True

    def getFront(self):
        if self.isEmpty():
            return -1 #注意这里是-1 而不是False
        else:
            return self.queue[self.start]

    def getRear(self):
        if self.isEmpty():#要带扩号
            print "empty"
            return -1
        index = (self.rear -1 ) % self.capacity
        return self.queue[index]
        

    def isEmpty(self):
        if self.start == self.rear:
            return True
        else:
            return False

    def isFull(self):
        if (self.rear + 1) % self.capacity == self.start: 
            return True
        else:
            return False



