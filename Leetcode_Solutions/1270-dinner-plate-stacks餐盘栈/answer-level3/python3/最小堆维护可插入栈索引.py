思路：暴力搜索的做法会超时，push 比较耗费时间，所以应该从这里下手优化，后面参考了海外版大神的做法进行优化，顺利 AC。

具体做法是维护一个最小堆，存放 popAtStack 有效弹出时的栈索引，push 的时候先从最小堆中找，如果没有找到可以 push 的有效栈索引，那么就只能从最后的栈 push 了。

为什么先从最小堆中找？这是因为 push 时候只有两个地方可以插入元素，一个是最后栈，另一个就是之前 popAtStack 操作有效弹出元素时留下的“坑”，很明显 popAtStack 弹出的栈位置最右不超过当前最后栈，所以，先填“坑”，再“追尾”。

需要注意的点是 pop 时需要清理最后空的栈，popAtStack 则不需要清理。


```python []
class DinnerPlates:

    def __init__(self, capacity: int):
        self.stackList = []
        self.capacity = capacity
        self.popAtHeap = []
        

    def push(self, val: int) -> None:
        ind = None
        # 先从最小堆中找有效索引
        while self.popAtHeap:
            ind = heapq.heappop(self.popAtHeap)
            if ind < len(self.stackList) and len(self.stackList[ind]) < self.capacity:
                break
        # 找不到有效的 index 的话只能在最后的栈 push
        if ind is None:
            # 没有栈或者最后一个栈满了，需要新开一个
            if not self.stackList or len(self.stackList[-1]) == self.capacity:
                self.stackList.append([])
            ind = -1
        self.stackList[ind].append(val)
        

    def pop(self) -> int:
        ret = -1
        for ind in reversed(range(len(self.stackList))):
            if self.stackList[ind]:
                ret = self.stackList[ind].pop()
                break
        for _ in reversed(range(len(self.stackList))):
            if not self.stackList[-1]:
                self.stackList.pop()
            else:
                break
        return ret
        

    def popAtStack(self, index: int) -> int:
        if index >= len(self.stackList):
            return -1
        ret = -1
        if self.stackList[index]:
            ret = self.stackList[index].pop()
            # 把弹出栈索引放到最小堆中
            heapq.heappush(self.popAtHeap,index)
        return ret


# Your DinnerPlates object will be instantiated and called as such:
# obj = DinnerPlates(capacity)
# obj.push(val)
# param_2 = obj.pop()
# param_3 = obj.popAtStack(index)
```