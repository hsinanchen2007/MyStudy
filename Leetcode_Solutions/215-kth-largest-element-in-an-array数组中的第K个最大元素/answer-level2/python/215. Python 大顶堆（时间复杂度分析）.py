### 解题思路
这道题很容易想到的方法是先排序再直接放回第k大的数字，如果使用常用的排序方法，那么排序的时间复杂度为O(nlogn)。
而堆也就是优先队列，可以保证每次可以pop的是最值，那么这时候建堆的时间复杂度为O(n)，pop的时间复杂度是O(logn)，而返回第k大的数需要pop k次，所以pop的总时间复杂度为O(klogn)，由于k <= n，所以O(n) < O(klogn) + O(n) <= O(nlogn) + O(n) = O(nlogn)，即采用堆方法的时间复杂度低于使用排序的方法。

### 代码

```python
class Heap:
    def __init__(self):
        self.heap = [0] # 0位置不使用，从1开始装入元素
        self.num = 0

    def push(self, val):
        """
        从堆尾添加元素，从下往上调整
        """
        self.num += 1
        ind = self.num
        if len(self.heap) < self.num + 1:
            self.heap.append(val)
        else:
            self.heap[ind] = val
        while ind > 1 and self.heap[ind >> 1] < self.heap[ind]:
            temp = self.heap[ind >> 1]
            self.heap[ind >> 1] = self.heap[ind]
            self.heap[ind] = temp
            ind = ind >> 1 

    def pop(self):
        """
        返回堆顶元素，从上往下调整
        """
        if self.is_empty():
            raise Exception('heap is empty')
        ind = self.num
        max_num = self.heap[1]
        temp = self.heap[1]
        self.heap[1] = self.heap[self.num]
        self.heap[self.num] = temp
        ind = 1
        while ind << 1 < self.num: # 这里已经不计算原来堆顶的元素
            swap_ind = ind
            if self.heap[ind << 1] > self.heap[ind]:
                swap_ind = ind << 1
            if (ind << 1) + 1 < self.num and self.heap[(ind << 1) + 1] > self.heap[swap_ind]:
                swap_ind = (ind << 1) + 1 # 这里一定要打括号，位运算优先级低于加减
            if swap_ind == ind:
                break
            temp = self.heap[ind]
            self.heap[ind] = self.heap[swap_ind]
            self.heap[swap_ind] = temp
            ind = swap_ind
        self.num -= 1
        return max_num

    def is_empty(self):
        if self.num == 0:
            return True
        return False

    def get_heap(self, data):
        """
        基于push()操作，一次接受一个列表得到一个堆
        """
        for num in data:
            self.push(num)

class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        heap = Heap()
        heap.get_heap(nums)
        res = 0
        for _ in range(k):
            res = heap.pop()

        return res
```