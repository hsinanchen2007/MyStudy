### 使用大根堆和小根堆
- 假想我们现在有两个容器 A, B 这两个容器将我们的整体数据分成两部分,且 A 中的数据都小于 B 中的数据,并且 A 中的最后一个数据是 A 里面最大的
- B 的第一个数据是 B 中最小的.
- 好了 我们有了上面的条件,那我们怎么找到中位数呢?
- 当整体数目为奇数时,中间的那个数就是所求.当整体数目为偶数时,中间两个数的和再除以 2 ,就能得到结果
- 但这和我们上面的两个容器有什么关系呢?
- 我们只要将上面的两个容器的数据数目只差保持在 1 之内即可,也就是说 A 和 B 将整体数据以中位数划分开来了
![image.png](https://pic.leetcode-cn.com/ceee5fae09a7ce4bcb74c2191d482d12226a19f48705704b463d615a9176e9f1-image.png)

### 代码

```python
class MedianFinder(object):
    from heapq import *
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.bigHpeap = []
        self.smallHeap = []
    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        if len(self.bigHpeap) == len(self.smallHeap):#总数为偶数时,先插入到大根堆,在插入到小根堆
            heapq.heappush(self.smallHeap, -heapq.heappushpop(self.bigHpeap, -num))
        else:#总数为奇数时,先插入到小根堆,在插入到大根堆
            heapq.heappush(self.bigHpeap, -heapq.heappushpop(self.smallHeap, num))

    def findMedian(self):
        """
        :rtype: float
        """
        if len(self.bigHpeap) == len(self.smallHeap):
            return (-self.bigHpeap[0] + self.smallHeap[0]) / 2.0
        else:
            return self.smallHeap[0]



# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
```