### 解题思路
思路简单明了

### 代码

```python3
class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        A.sort()
        if A[0] == 0:  # 若最小数字为0，无需任何反转
            return sum(A)
        i = 0
        while K > 0 and A[i] < 0:  # 若存在小于0的数字，从小到大依次反转
            A[i] = -A[i]
            i += 1
            K -= 1
        if K == 0 or A[i] == 0:  # 若反转完了K次或反转到了数字0，后续无效
            return sum(A)
        K = K % 2  # 对剩余次数求余
        if K == 1:  # 为奇数时需要反转，此时应该反转最小的数，而最小的数一定存在于i和i - 1位之中
            if A[i] > A[i - 1]:
                A[i - 1] = -A[i - 1]
            else:
                A[i] = -A[i]
        return sum(A)
        
```