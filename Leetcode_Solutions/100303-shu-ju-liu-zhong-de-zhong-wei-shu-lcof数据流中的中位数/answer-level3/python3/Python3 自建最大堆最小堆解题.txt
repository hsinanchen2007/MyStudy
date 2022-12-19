```
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.bigHeap = MaxHeap()
        self.smallHeap = MaxHeap()

    def addNum(self, num: int) -> None:
        if len(self.bigHeap.data) == len(self.smallHeap.data):
            self.bigHeap.insert(num)
            self.smallHeap.insert(-self.bigHeap.extract_max())
        else:
            self.smallHeap.insert(-num)
            self.bigHeap.insert(-self.smallHeap.extract_max())

    def findMedian(self) -> float:
        if len(self.bigHeap.data) == len(self.smallHeap.data):
            return (-self.smallHeap.data[1] + self.bigHeap.data[1]) / 2
        else:
            return -self.smallHeap.data[1]
class MaxHeap:
    def __init__(self):
        self.count = 0
        self.data = [None]

    def __sink(self,k):
        temp = self.data[k]
        while 2 * k <= self.count:
            j = 2 * k
            if j + 1 <= self.count and self.data[j + 1] > self.data[j]:
                j += 1
            if self.data[k] > self.data[j]:
                break
            self.data[k],self.data[j] = self.data[j],self.data[k]
            k = j
        self.data[k] = temp

    def __swim(self,k):
        temp = self.data[k]
        while k > 1 and self.data[k // 2] < temp:
            self.data[k] = self.data[k // 2]
            k //= 2
        self.data[k] = temp

    def insert(self,data):
        self.count += 1
        # self.data[self.count] = data
        self.data.append(data)
        self.__swim(self.count)

    def extract_max(self):
        ret = self.data[1]
        self.data[1],self.data[self.count] = self.data[self.count],self.data[1]
        self.count -= 1
        self.__sink(1)
        self.data.pop()
        return ret
```
