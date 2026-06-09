**考虑可以将数据分两个堆存放，左侧为最大堆，右侧为最小堆。尽量保持两个堆中的元素个数相等。当向堆中插入元素时需要分两种情况讨论：当两个堆长度相等，需要先将元素压入最大堆，再将堆顶弹入最小堆；反之亦反之（可以考虑为什么不能直接压入最大堆）。查找中位数时，若两个堆长度相等，则返回两个堆顶的均值；否则，返回最小堆堆顶。**

## 示例代码

    def __init__(self):
        """
        initialize your data structure here.
        """
        import heapq
        #最大堆：
        self.q1 = []
        #最小堆：
        self.q2 = []

    def addNum(self, num):
        """
        :type num: int
        :rtype: None
        """
        #分情况讨论：
        if len(self.q1) == len(self.q2):
            heapq.heappush(self.q1, -num)
            num = -heapq.heappop(self.q1)
            heapq.heappush(self.q2, num)
        else:
            heapq.heappush(self.q2, num)
            num = heapq.heappop(self.q2)
            heapq.heappush(self.q1, -num)

    def findMedian(self):
        """
        :rtype: float
        """
        if len(self.q1) == len(self.q2):
            return 0.5 * (-self.q1[0] + self.q2[0])
        else:
            return self.q2[0]