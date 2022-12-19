### 解题思路
队列顾名思义：先进先出，后进后出。入队从tail加，出队从head出。循环：利用cache中先进先出后空出来的空间，存储后面进入队列的元素

初始化：
1. 申请和size对应的空间。
2. 记录空间最大的长度max_len和队列中的元素个数real_len（这个可以使得队列实现清晰，也可以方便你自己定义一个len()函数或者MyCircularQueue.length()读取长度。
3. 同时需要初始化head和tail两个指针，在循环队列中对应的是queue的下标。

入队 (enQueue）：
1. 如果queue为空，此时待加入的元素作为第一个元素加入，需要先初始化head和tail两个下标指针，更新real_len记录，返回True
2. 如果queue满了，返回False
3. 如果queue非空也非满，说明queue有空间，更新real_len记录，则将目标值加入队列，更新tail即可

出队 (deQueue):
1. 如果queue为空，返回False
2. 如果queue非空，说明queue有元素可以删，则把head指向元素删掉，更新real_len记录，更新head即可

队头 (Font):
1. 如果head不为None，说明列表中有元素，则返回head所指但元素内容
2. 如果head为None，说明列表real_len=0，返回-1

队尾 (Rear):
1. 如果head不为None，说明列表中有元素，则返回head所指但元素内容
2. 如果head为None，说明列表real_len=0，返回-1

队列是否为空 or 队列是否已满（isEmpty or isFull):
根据real_len判断判断True or False，简单也清晰

**可能存在的疑惑：head和tail真实的指针值如何确定？**
首先需要想明白的是在不考虑 “out of index“ 的情况下我们无论更新head或者tail指针都是对target_pointer + 1, 这也是普通队列空间浪费的根源（出队后原本申请的队头存储空间全部闲置),为了重新利用这部分的空间我们对head和tail的真实取值作处理，这里因为head和tail逻辑一致，接下来我使用target_pointer代替。
正常情况下，new_target_pointer = target_pointer + 1
如果new_target_pointer大于队列的size的话，那new_target_pointer则真正应该指向队列之前的被闲置的空间，即target + 1 - max_len

### 代码

```python3
class MyCircularQueue:

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        self.queue = []
        self.head = None
        self.tail = None
        self.real_len = 0
        self.max_len = k
        for i in range(0, k):
            self.queue.append({'val': None})

    def enQueue(self, value: int) -> bool:
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        rst = True

        # 如果是第一个元素
        if self.isEmpty():
            self.head = 0
            self.tail = 0
            self.queue[self.head]['val'] = value
            self.real_len += 1
        elif self.isFull():
            rst = False
        else:
            self.tail = self.tail + 1 if self.tail + 1 < self.max_len else self.tail + 1 - self.max_len
            self.queue[self.tail]['val'] = value
            self.real_len += 1
        return rst

    def deQueue(self) -> bool:
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        rst = True

        # 如果是第一个元素
        if self.isEmpty():
            rst = False
        else:
            self.queue[self.head]['val'] = None
            self.real_len -= 1
            self.head = self.head + 1 if self.head + 1 < self.max_len else self.head + 1 - self.max_len
            if self.real_len == 0:
                self.head = None
                self.tail = None
        return rst

    def Front(self) -> int:
        """
        Get the front item from the queue.
        """
        rst = -1
        if self.head is not None:
            rst = self.queue[self.head]['val']
        return rst

    def Rear(self) -> int:
        """
        Get the last item from the queue.
        """
        rst = -1
        if self.tail is not None:
            rst = self.queue[self.tail]['val']
        return rst

    def isEmpty(self) -> bool:
        """
        Checks whether the circular queue is empty or not.
        """
        rst = False
        if self.real_len == 0:
            rst = True
        return rst

    def isFull(self) -> bool:
        """
        Checks whether the circular queue is full or not.
        """
        rst = False
        if self.real_len == self.max_len:
            rst = True
        return rst
```