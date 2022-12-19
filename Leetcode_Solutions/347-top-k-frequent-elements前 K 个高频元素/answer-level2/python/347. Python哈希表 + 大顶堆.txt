### 解题思路
对于要输出第几大或者第几小的值的问题，应该首先想到用堆来解决，相比于先进行排序的方法来说，使用堆具有更低的时间复杂度。

### 代码

```python
class Heap:
    def __init__(self):
        self.heap = [(0, 0)] # (num, num出现的次数)
        self.cnt = 0

    def push(self, x):
        x = self.heap.append(x)
        self.cnt += 1
        ind = self.cnt
        while ind > 1:
            if self.heap[ind][1] > self.heap[ind >> 1][1]:
                temp = self.heap[ind]
                self.heap[ind] = self.heap[ind >> 1]
                self.heap[ind >> 1] = temp
                ind = ind >> 1
            else:
                break

    def pop(self):
        max_num = self.heap[1][0]
        ind = self.cnt
        self.heap[1] = self.heap[ind]
        del self.heap[-1]
        self.cnt -= 1
        ind = 1
        while ind << 1 <= self.cnt:
            swap_ind = ind
            if self.heap[ind << 1][1] > self.heap[ind][1]:
                swap_ind = ind << 1
            if (ind << 1) + 1 <= self.cnt and self.heap[(ind << 1) + 1][1] > self.heap[swap_ind][1]:
                swap_ind = (ind << 1) + 1
            if swap_ind == ind:
                break
            temp = self.heap[ind]
            self.heap[ind] = self.heap[swap_ind]
            self.heap[swap_ind] = temp
            ind = swap_ind
            
        return max_num


class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        num_dict = {}
        heap = Heap()
        res = []
        for num in nums:
            num_dict[num] = num_dict.get(num, 0) + 1
        for x in num_dict.items():
            heap.push(x)
        for _ in range(k):
            res.append(heap.pop())
        return res
```