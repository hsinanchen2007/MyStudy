### 解题思路-二分法
对于山脉数组的特点，如果其`mid`位置在局部升序序列中，则其峰值位置在`mid+1~right`中；如果在局部降序序列中，则其峰值位置在`left~mid`中；

因此可以用二分的方法，每次迭代将搜索空间减半；
时间复杂度：`O(log n)`；
空间复杂度：`O(1)`；

### 代码

```python3
class Solution:
    """
    与第162题类似，不同之处在于：第162题中可能存在多个峰值，找到其中任一个贬值；而本题数组中只有一个峰值，找到该峰值；
    用二分法进行寻找；
    """
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        left, right = 0, len(A)-1
        while left < right:
            mid = (left+right)>>1
            if A[mid] < A[mid+1]:
                left = mid+1
            else:
                right = mid
        return left
```