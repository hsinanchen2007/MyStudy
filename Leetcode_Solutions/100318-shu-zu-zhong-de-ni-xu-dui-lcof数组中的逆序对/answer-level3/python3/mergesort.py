### 解题思路
仅需要修改mergesort中非常少量的代码，在归并两个排好序的数组时，出现了左边数组元素大于右边数组元素，则左边数组剩余的元素均大于右边该元素，因此可以求出逆序对。

### 代码

```python3
import copy
class Solution:
    def __init__(self):
        self.nums = None
        self.tmp = None
    def merge(self, l, m, r):
        i, j, k = l, m+1, l
        cnt = 0
        while (i<=m) and (j<=r):
            if self.nums[i]<=self.nums[j]:
                self.tmp[k] = self.nums[i]
                k += 1
                i += 1
            else:
                self.tmp[k] = self.nums[j]
                k += 1
                j += 1
                cnt += (m-i+1)
        if i>m:
            while j <= r:
                self.tmp[k] = self.nums[j]
                k += 1
                j += 1
        else:
            while i <= m:
                self.tmp[k] = self.nums[i]
                k += 1
                i += 1
        
        self.nums[l:r+1] = self.tmp[l:r+1]
        return cnt

    def mergesort(self, l, r):
        if l>=r:
            return 0
        mid = (l+r)//2
        cnt0 = self.mergesort(l, mid)
        cnt1 = self.mergesort(mid+1, r)
        cnt = self.merge(l, mid, r)
        return cnt+cnt0+cnt1

    def reversePairs(self, nums: List[int]) -> int:
        self.nums = copy.deepcopy(nums)
        self.tmp = copy.deepcopy(nums)
        return self.mergesort(0, len(nums)-1)
```