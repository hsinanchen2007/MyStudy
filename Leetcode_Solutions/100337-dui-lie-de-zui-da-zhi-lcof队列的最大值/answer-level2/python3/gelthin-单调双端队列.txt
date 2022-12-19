### 解题思路
参考[官方题解-面试题59 - II. 队列的最大值](https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-ii-dui-lie-de-zui-da-zhi-by-leetcod/)

与习题 [155. 最小栈](https://leetcode-cn.com/problems/min-stack/) 异曲同工之妙。

在习题也用到了单调栈的思想， [496. 下一个更大元素 I-gelthin-单调栈-巧妙](https://leetcode-cn.com/problems/next-greater-element-i/solution/gelthin-zhe-yi-ge-ti-mu-fei-chang-qiao-miao-by-gel/)

这里也是用到了非同步单调双端队列的思想。
就是要注意，什么时候更新单调双端队列的头部元素。


### 代码

```python3
class MaxQueue:

    def __init__(self):
     ## 其实可以直接使用链表来模拟队列，双短队列，栈等
        self.queue = []
        self.dequeue = []  # 单调双端队列  ## 自然地是一个非同步队列，比上面短

    def max_value(self) -> int:
        if self.dequeue:
            return self.dequeue[0]
        else:
            return -1

    def push_back(self, value: int) -> None:
        self.queue.append(value)
        while self.dequeue and self.dequeue[-1] < value:  ## > 或 == 都要加进去
            self.dequeue.pop(-1)
        self.dequeue.append(value)

    def pop_front(self) -> int:
        if not self.queue:
            return -1
        elif self.queue[0] == self.dequeue[0]:
            self.dequeue.pop(0)
            return self.queue.pop(0)
        else:
            return self.queue.pop(0)


# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```