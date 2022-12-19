```
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.__data = []
        self.size = 0


    def addNum(self, num: int) -> None:
        lo, hi = 0, len(self.__data)
        tem_index = self.__binary_search_for_insert_index(lo,hi,num)
        self.__data.insert(tem_index, num)
        self.size += 1
    
    # 借助二分法用收紧右边界，找左边界方法插入数据使数组有序，logn
    def __binary_search_for_insert_index(self, lo, hi, target) -> int:
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if self.__data[mid] == target:
                hi = mid
            elif target < self.__data[mid]:
                hi = mid
            else:
                lo = mid + 1
        return lo


    def findMedian(self) -> float:
        if self.size % 2 == 0:  # 偶数情况
            return self.__data[self.size // 2 - 1] / 2 + self.__data[self.size // 2] / 2
        else:                   # 奇数情况
            return self.__data[self.size // 2]

```