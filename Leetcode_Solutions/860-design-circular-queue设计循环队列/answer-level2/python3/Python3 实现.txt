## 示例代码：

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        #定义长度为k的列表
        self.queue = [None] * k
        self.length = k
        #定义首尾指针
        self.front = 0
        self.rear = 0

    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        #分别讨论队列为空或不为空的情况
        if self.isEmpty():
            self.queue[self.front] = value
            self.rear = self.front
            return True
        else:
            #下一个插入位置的计算公式：
            temp_rear = (self.rear + 1) % self.length
            #若下一个插入位置是列表的头部，说明列表已经满了
            if temp_rear == self.front:
                return False
        self.rear = temp_rear
        self.queue[self.rear] = value
        return True
    
    
    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if not self.isEmpty():
            self.queue[self.front] = None
            #如果删除后列表为空，则让front和rear位于同一位置
            if self.isEmpty():
                self.front = self.rear
            else:
                self.front = (self.front + 1) % self.length
            return True
        return False

    
    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        if self.isEmpty():
            return -1
        return self.queue[self.front]

    
    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        if self.isEmpty():
            return -1
        return self.queue[self.rear]

    
    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        if self.front != self.rear or self.queue[self.front] != None:
            return False
        return True
        

    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        temp_rear = (self.rear + 1) % self.length
        if temp_rear == self.front:
            return True
        return False
