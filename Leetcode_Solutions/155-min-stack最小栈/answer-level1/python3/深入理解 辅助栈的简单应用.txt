**思路：问题的关键在于，如何获得最小元素。一般需要排序算法获得最小元素，这里可以简单利用选择排序算法。**

选择排序思想：需要一个变量或这数据结构储存一个最小值。


题目特征：
1. 栈结构。由于栈可以进行pop()操作，可能会弹出最小的元素，所以需要利用辅助栈，存储最小的一些元素。
2. 获取最小值。可以直接返回辅助栈的最后一个元素。






```
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []
        self.helper = []

    def push(self, x: int) -> None:
        self.data.append(x)
        if len(self.helper)==0 or x <= self.helper[-1]:
            self.helper.append(x)

    def pop(self) -> None:
        top = self.data.pop()
        if self.helper and top == self.helper[-1]:
            self.helper.pop()
        return top
    def top(self) -> int:
        return self.data[-1]

    def getMin(self) -> int:
        return self.helper[-1]
```
