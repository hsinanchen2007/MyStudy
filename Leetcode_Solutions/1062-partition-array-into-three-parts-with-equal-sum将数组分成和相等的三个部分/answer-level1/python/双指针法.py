### 解题思路
构建左右两个指针，分别判断是否能够在左侧和右侧构建达到1/3大小的数组。注意判断条件

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        left, right = 0, len(A) - 1
        sum1, sum2, sum3 = 0, sum(A), 0
        while (sum1 != sum2 // 3 and left < right) or left == 0:
            sum1 += A[left]
            left += 1
        while (sum3 != sum2 // 3 and left < right) or right == len(A) - 1:
            sum3 += A[right]
            right -= 1
        left, right = left - 1, right + 1
        if left > right or sum1 != sum3 or left == right - 1:
            return False
        return True
```