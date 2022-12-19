### 解题思路
注意看懂题意!!! 题目是说输入数组顺序不变动的情况下, 找到划分数组为连续三段的方式.
那当然就是直接两个指针移动了, 最直接最符合题意.

注意处理一些奇怪的case就行.

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total = sum(A)
        if total % 3 != 0:
            return False
        i, j = -1, len(A)
        left_sum, right_sum = 0, 0
        while i < j - 1:
            if i < 0 or left_sum != total // 3:
                i += 1
                left_sum += A[i]
            if j > len(A) - 1 or right_sum != total // 3:
                j -= 1
                right_sum += A[j]
            if left_sum == total // 3 and right_sum == total // 3 and (j - i) >= 2 and i >= 0 and j <= len(A) - 1:
                return True
        return False
            
                
```