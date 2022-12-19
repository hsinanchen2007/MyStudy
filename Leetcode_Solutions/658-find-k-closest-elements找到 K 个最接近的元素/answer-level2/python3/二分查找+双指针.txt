### 解题思路

二分查找+双指针法

数组有序，二分查找到数组中第一个不小于x的数的位置，然后从这个地方开始向两个方向扩展区间。

时间复杂度`O(log n + k)`

### 代码

```python3
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        l = 0
        r = len(arr) - 1
        while l < r:
            mid = l + r >> 1
            if arr[mid] >= x:
                r = mid
            else:
                l = mid + 1
        
        if l == 0:
            return arr[:k]
        elif l == len(arr) - 1:
            return arr[-k:]
        else:
            # 表示区间[i, j)现在在满足条件
            if arr[l] == x:
                i = l
                j = l + 1
            else:
                if x - arr[l-1] <= arr[l] - x:
                    i = l - 1
                    j = l
                else:
                    i = l
                    j = l + 1
            while j - i < k:
                if i == 0:
                    j += 1
                    continue
                if j == len(arr):
                    i -= 1
                    continue
                if x - arr[i - 1] <= arr[j] - x:
                    i -= 1
                else:
                    j += 1
        return arr[i:j]
            
```