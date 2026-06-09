### 解题思路
归并排序思想（从大到小）

### 代码

```python3
class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        if not nums or len(nums) < 2:
            return 0
        return self.process(nums, 0, len(nums) - 1)

    def process(self, arr, L, R):
        if L == R:
            return 0
        mid = L + ((R - L) >> 2)
        return self.process(arr, L, mid) + \
               self.process(arr, mid + 1, R) + \
               self.merge(arr, L, mid, R)
    
    def merge(self, arr, L, M, R):
        helper = [None] * (R - L + 1)
        i = 0
        p1 = L
        p2 = M + 1
        res = 0

        while p1 <= M and p2 <= R:
            if arr[p1] > arr[p2]:
                res += R - p2 + 1
                helper[i] = arr[p1]
                p1 += 1
                i += 1
            else:
                helper[i] = arr[p2]
                p2 += 1
                i += 1
        
        while p1 <= M:
            helper[i] = arr[p1]
            i += 1
            p1 += 1

        while p2 <= R:
            helper[i] = arr[p2]
            i += 1
            p2 += 1
        
        for i in range(len(helper)):
            arr[L + i] = helper[i]
        return res
```