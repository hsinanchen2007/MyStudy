# 无边界情况
# 分两个大小顶堆，左边为大顶堆，右边为小顶堆，（默认大顶堆的数量大于等于小顶堆）
    # 如果大顶堆的数量等于小顶堆，add的时候先将数顶堆插入大顶堆，再从大顶堆取出最小的数插入小顶堆；
    # 如果小顶堆的数量大于大顶堆，add的时候将数插入小顶堆，再从小顶堆中取出最小的数插入大顶堆。

```
# 无边界情况
# 分两个大小顶堆，左边为大顶堆，右边为小顶堆，（默认大顶堆的数量大于等于小顶堆）
    # 如果大顶堆的数量等于小顶堆，add的时候先将数顶堆插入大顶堆，再从大顶堆取出最小的数插入小顶堆；
    # 如果小顶堆的数量大于大顶堆，add的时候将数插入小顶堆，再从小顶堆中取出最小的数插入大顶堆。

class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.left = []
        self.right = []
        

    def addNum(self, num: int) -> None:
        if len(self.left) == len(self.right)-1:
            self.right.append(num)  
            # self._swap_min(0,len(self.right)-1)
            self._upheap_min(len(self.right)-1)
            self._swap_min(0,len(self.right)-1)
            
            self.left.append(self.right.pop())
            if len(self.right)>0:
                self._downheap_min(0)
            

            self._upheap_max(len(self.left)-1)
        else:
            self.left.append(num)
            self._upheap_max(len(self.left)-1)
            self._swap_max(0, len(self.left)-1)
            self.right.append(self.left.pop())
            if len(self.left)>0:
                self._downheap_max(0)
            self._upheap_min(len(self.right)-1)  
            # print(self.right)
    def findMedian(self) -> float:
        if len(self.left) == len(self.right): 
            if len(self.left) > 0: return (self.left[0] + self.right[0]) /2
            else: return -1
        else:
            # print(self.left, self.right)
            return self.right[0]
            
    
    def _swap_min(self, i, j):
        self.right[i], self.right[j] = self.right[j], self.right[i]
    
    def _swap_max(self, i, j):
        self.left[i], self.left[j] = self.left[j], self.left[i]
    
    def _p(self, i):
        return (i-2) >> 1 if i%2==0 else i >> 1
    
    def _l(self, i):
        return (i<<1) + 1
    def _r(self, i):
        return (i<<1) + 2
        
    # 向上维护小顶堆
    def _upheap_min(self, i):
        if i > 0 and self.right[i] < self.right[self._p(i)]:
            self._swap_min(i, self._p(i))
            self._upheap_min(self._p(i))
    # 向上维护大顶堆
    def _upheap_max(self, i):
        if i > 0 and self.left[i] > self.left[self._p(i)]:
            self._swap_max(i, self._p(i))
            self._upheap_max(self._p(i))
            # print('test {}'.format(self.left))
    
    # 向下维护小顶堆
    def _downheap_min(self,i):
        if self._l(i) <= len(self.right)-1 or self._r(i) <= len(self.right)-1:
            if self._r(i) <= len(self.right)-1 and self.right[self._r(i)] < self.right[self._l(i)]:
                min_child = self._r(i)
                # print('min is{}'.format(min_child))
            else: min_child = self._l(i)
            if self.right[i] > self.right[min_child]: 
                # print('i,min_child is {},{}'.format(i,min_child))
                self._swap_min(i, min_child)
                self._downheap_min(min_child)
    # 向下维护大顶堆
    def _downheap_max(self,i):
        if self._r(i) <= len(self.left)-1 or self._l(i) <= len(self.left)-1:
            if self._r(i) <= len(self.left)-1 and self.left[self._r(i)] > self.left[self._l(i)]:
                max_child = self._r(i)
            else: max_child = self._l(i)
            if self.left[i] < self.left[max_child]: 
                self._swap_max(i, max_child)
                self._downheap_max(max_child)
# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
```
