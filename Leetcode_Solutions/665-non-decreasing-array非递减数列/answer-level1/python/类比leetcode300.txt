### 解题思路
O(nlogn)类比于300题最长上升子序列，改为非递减，同时如果长度>=n-1,说明改变一个就可以。

### 代码

```python3
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        if not nums:
            return True
        n = len(nums)
        tail = [0] * n
        res = 0
        for num in nums:
            l, r = 0, res
            while l < r:
                mid = (l + r) // 2
                if num < tail[mid]:
                    r = mid
                else:
                    l = mid + 1

            tail[l] = num
            if r == res:
                res += 1

        
        return True if res >= n - 1 else False
```