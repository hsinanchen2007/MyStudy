### 解题思路
标准的二分查找模板

### 代码

```python3
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        left = 0
        right = max(arr)
        n = len(arr)
        arr = sorted(arr)
        res = float('inf')
        ans = max(arr)
        while left <= right:
            mid = (left + right) // 2
            s = 0
            for i in range(len(arr)):
                if arr[i] < mid:
                    s += arr[i]
                else:
                    break
            s += (n - i) * mid
            if s == target:
                return mid
            elif s > target:
                right = mid - 1
                if s - target < res:
                    ans = mid
                    res = s - target
                elif s - target == res:
                    ans = min(mid,ans)
            elif s < target:
                left = mid + 1
                if abs(s - target) < res:
                    ans = mid
                    res = abs(s - target)
                elif abs(s - target) == res:
                    ans = min(mid,ans)
        return ans
```