### 解题思路
参考大神的解题思路写的，就一个疑问，我手写的二分搜索和插入就不行呗？到底差在哪里呢？我写的二分搜索和插入就会超时？bisect牛逼嗷！

### 代码

```python3
import bisect
class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        m, n = len(matrix), len(matrix[0])
        preSum = [[0 for _ in range(n+1)] for _ in range(m)]
        
        for i in range(m):
            for j in range(1, n+1):
                preSum[i][j] = preSum[i][j-1] + matrix[i][j-1]
                
        res = float('-inf')
        for colA in range(1, n+1):
            for colB in range(colA, n+1):
                slist, cur = [0], 0
                for row in range(m):
                    cur += preSum[row][colB] - preSum[row][colA-1]
                    # idx = self.bsearch(slist, cur-k)
                    idx = bisect.bisect_left(slist, cur-k)
                    if idx < len(slist):
                        res = max(res, cur-slist[idx])
                    # insert_idx = self.bsearch(slist, cur)
                    # slist.insert(insert_idx, cur)
                    bisect.insort(slist, cur)
        return res
                    
    
    def bsearch(self, nums, target):
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) >> 1
            if nums[mid] >= target:
                r = mid - 1
            else:
                l = mid + 1
        return l
```