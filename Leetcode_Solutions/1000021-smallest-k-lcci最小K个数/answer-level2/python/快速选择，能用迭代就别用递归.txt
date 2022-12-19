### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def smallestK(self, arr: List[int], k: int) -> List[int]:
        if k == 0:
            return []
        divide = len(arr) - 1
        lo = 0
        hi = len(arr) - 1
        k1 = k
        while divide - lo + 1 != k1:
            pivot = arr[hi]
            i = lo-1
            for j in range(lo, hi):
                if arr[j] < pivot:
                    i += 1
                    arr[j], arr[i] = arr[i], arr[j]
            arr[hi], arr[i+1] = arr[i+1], arr[hi]
            divide = i + 1

            if divide - lo + 1 < k1:
                k1 = k1 - (divide - lo + 1)
                lo = divide + 1
            elif divide - lo + 1 > k1:
                hi = divide - 1
                
        return arr[:k]




        




```