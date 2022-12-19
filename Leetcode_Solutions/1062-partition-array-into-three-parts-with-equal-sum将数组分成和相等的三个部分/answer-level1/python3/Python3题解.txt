![1.png](https://pic.leetcode-cn.com/fbf24d821f0b1dff1fab7746446fedd1d41f9a22cf90a775dc74fec6b9575d51-1.png)
```python
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        sumOfThree = sum(A)
        if sumOfThree % 3 != 0:  # 如果数组总和不为3的倍数直接返回
            return False
        sum1 = 0  # 记录第一组三分之一
        sum2 = 0  # 记录第二组三分之一
        for i in range(len(A)-2):
            sum1 += A[i]
            if sum1 == sumOfThree / 3:  # 如果找到了第一组就继续找第二组
                for j in range(i+1, len(A)-1):
                    sum2 += A[j]
                    if sum2 == sumOfThree / 3:  # 如果满足两组三分之一则正确
                        return True
        return False
```