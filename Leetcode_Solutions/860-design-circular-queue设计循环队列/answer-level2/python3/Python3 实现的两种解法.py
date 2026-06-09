# 方法一
> 为存储的 list 多开辟一块存储空间，
1. 通过`队首`和`队尾` 是否相同来判断队列是否已满
2. 通过`队首`和`队尾 + 1` 是否相同来判断队列是否已满
3. 通过`取模`运算获取正确的下标

代码和注释如下：
```
class MyCircularQueue:

    def __init__(self, k: int):
        # 队列容量，比需要的多 1
        self._capacity = k + 1
        # 初始化队列
        self._list = [None] * self._capacity
        # 初始化队首和队尾下标
        self._front = 0
        self._rear = 0

    def enQueue(self, value: int) -> bool:
        # 如果尾部 +1 的下标和首部相同，则说明已经队满
        # 所以尾部所在位置是没有存数据的，这就是为什么要多开辟一个空间的原因
        if (self._rear + 1) % self._capacity == self._front:
            return False
        # 如果没有队满
        # 在尾部添加数据
        self._list[self._rear] = value
        # 尾部指针向后移一位
        self._rear = (self._rear + 1) % self._capacity
        return True

    def deQueue(self) -> bool:
        # 如果队首和队尾的下标相同，则说明没有数据
        if self._rear == self._front:
            return False
        # 如果有数据，则将队首指针向后移 1，无需清空数据的原因是已经访问不到，下次需要入队的时候会覆盖
        self._front = (self._front + 1) % self._capacity
        return True
        
    def Front(self) -> int:
        # 队列不为空的时候，返回队首数据
        return -1 if self._rear == self._front else self._list[self._front]
        
    def Rear(self) -> int:
        # 队列不为空的时候，返回队尾数据
        return -1 if self._rear == self._front else self._list[(self._rear - 1) % self._capacity]

    def isEmpty(self) -> bool:
        # 和上面一样，两个下边相同说明队列为空
        return self._rear == self._front

    def isFull(self) -> bool:
        # 如果队尾下标 +1 和队首下标相同，则说明队满
        return (self._rear + 1) % self._capacity == self._front

```

# 方法二
> 多一个变量存储当前的队列数据个数
1. 通过获取`当前数据个数`是否为 0 来判断队列是否为空
2. 通过判断`当前数据个数`和`队列容量`来判断队列是否已满
3. 通过`取模`运算获取正确的下标

代码和注释如下：
```
class MyCircularQueue:

    def __init__(self, k: int):
        # queue 的容量
        self._capacity = k
        # 初始化 list
        self._list = [None] * self._capacity
        # 存储队首下标
        self._front = 0
        # 存储队尾下标
        self._rear = -1
        # 当前数据个数
        self._size = 0

    def enQueue(self, value: int) -> bool:
        # 如果存储的数据达到最大容量，则不能继续添加
        if self._size == self._capacity:
            return False
        # 队尾 + 1（取模是为了下标不超出）
        self._rear = (self._rear + 1) % self._capacity
        # 将新的值设置到队尾
        self._list[self._rear] = value
        # 存储数据个数 +1
        self._size += 1
        return True

    def deQueue(self) -> bool:
        # 如果没有数据，则无法出队
        if 0 == self._size:
            return False
        # 将首坐标 +1，无需清空数据，因为也访问不到，下次设置的时候会覆盖
        self._front = (self._front + 1) % self._capacity
        # 数据个数 -1
        self._size -= 1
        return True

    def Front(self) -> int:
        # 没有数据
        if 0 == self._size:
            return -1
        # 返回队首数据
        return self._list[self._front]
        
    def Rear(self) -> int:
        # 没有数据
        if 0 == self._size:
            return -1
        # 返回队尾数据
        return self._list[self._rear]

    def isEmpty(self) -> bool:
        # 队列为空的判断
        return 0 == self._size

    def isFull(self) -> bool:
        # 队列已满的判断
        return self._size == self._capacity
```
