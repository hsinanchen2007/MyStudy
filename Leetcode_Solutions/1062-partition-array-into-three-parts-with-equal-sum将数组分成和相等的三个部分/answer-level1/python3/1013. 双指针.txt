### 解题思路
1. 计算算A的累加和能否被3整除，不可以那分不了3等分。
2. 左右指针前后向中间移动，因为可以被3整除，不用考虑中间那段怎么分，只要左右两段累加和等于3等分的数值，中间剩的那段也就找到了。

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if sum(A) % 3 != 0:
            return False
        
        left, right = 0, len(A)-1

        average = int(sum(A) / 3)

        left_sum, right_sum = 0, 0
        while left < right:
            if left_sum != average:
                left_sum += A[left]
                left += 1
            
            if right_sum != average:
                right_sum += A[right]
                right -= 1

            if left_sum == average and right_sum == average:
                return True   
            
        return False
```