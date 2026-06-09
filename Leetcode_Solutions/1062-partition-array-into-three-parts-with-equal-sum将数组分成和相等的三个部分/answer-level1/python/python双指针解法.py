### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def canThreePartsEqualSum(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        sum_A = sum(A)
        if sum_A % 3 != 0:
            return False
        target = sum_A / 3
        if len(A) < 3:
            return False
        
        l_sum = A[0]
        r_sum = A[-1]
        i = 0
        j = len(A) - 1
        while i+1 < j:
            if l_sum != target:
                i += 1
                l_sum += A[i]
            if r_sum != target:
                j -= 1
                r_sum += A[j]
            if target == r_sum and l_sum == target and i + 1 < j:
                return True

        return False
```