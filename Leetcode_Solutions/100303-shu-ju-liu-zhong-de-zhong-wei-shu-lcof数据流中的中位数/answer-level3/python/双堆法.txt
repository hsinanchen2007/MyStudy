### 解题思路
思路见代码中的注释
    双堆法：大顶堆存放比中位数小的所有数，小顶堆存放比中位数大的所有数。
    在整个过程中，我们要保证两个堆中的元素数量之差是小于等于1的。
    1. 如果插入的数据总数是偶数，则弹出两个堆的堆顶元素相加然后除以2得到中位数；
    2. 如果插入的数据总数是奇数，我们设定中位数是小顶堆的堆顶元素（在奇数情况下，小顶堆元素数量比大顶堆多1）

### 代码

```python3
class MedianFinder:
    """
    双堆法：大顶堆存放比中位数小的所有数，小顶堆存放比中位数大的所有数。
    在整个过程中，我们要保证两个堆中的元素数量之差是小于等于1的。
    1. 如果插入的数据总数是偶数，则弹出两个堆的堆顶元素相加然后除以2得到中位数；
    2. 如果插入的数据总数是奇数，我们设定中位数是小顶堆的堆顶元素（在奇数情况下，小顶堆元素数量比大顶堆多1）
    ps: 当然也可以设定中位数是大顶堆的堆顶元素，只是代码实现不同而已。
    """

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.bighp = [] # 存放比中位数小的数
        self.smallhp = [] # 存放比中位数大的数
        

    def addNum(self, num: int) -> None:
        # 如果现在添加的数据总量是偶数，但插入新的一条数据后，会让数据总量变为奇数，则
        # 先将这个数放到大顶堆中，重新进行大顶堆的排序，然后弹出大顶堆的最大值放到小顶堆里,
        # 这个时候保证了小顶堆元素数量比大顶堆多1
        if len(self.bighp) == len(self.smallhp):
            heapq.heappush(self.smallhp, -heapq.heappushpop(self.bighp, -num))
        # 新增数据使得数据总量变成偶数，因为在奇数的时候，小顶堆的元素数量比大顶堆元素数量多1，
        # 所以我们把新添加的数据放到大顶堆里，使得两堆元素数量相等
        else:
            heapq.heappush(self.bighp, -heapq.heappushpop(self.smallhp,num))


    def findMedian(self) -> float:
        if len(self.bighp) == len(self.smallhp):
            return (-self.bighp[0] + self.smallhp[0]) / 2
        else:
            return self.smallhp[0]



# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
```