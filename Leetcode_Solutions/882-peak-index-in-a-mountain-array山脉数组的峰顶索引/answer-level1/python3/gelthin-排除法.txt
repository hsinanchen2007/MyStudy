### 解题思路
此题同 [162. 寻找峰值](https://leetcode-cn.com/problems/find-peak-element/)
见题解 [162. 题解排除法](https://leetcode-cn.com/problems/find-peak-element/solution/pai-chu-fa-by-gelthin-2/)

### 代码

```python3
class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        n = len(A)
        if A[0]>A[1]:
            return 0
        if A[n-2]<A[n-1]:
            return n-1

        a, b = 1, n-2
        while a<b:
            mid = a + (b-a+1)//2
            if A[mid-1]<A[mid]:
                a = mid
            else:
                b = mid-1
        return a
```