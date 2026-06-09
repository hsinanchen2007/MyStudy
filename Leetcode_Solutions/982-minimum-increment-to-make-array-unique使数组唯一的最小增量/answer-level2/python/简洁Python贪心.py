### 解题思路
贪心算法

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        # 数组排序之后，可以通过保证数组的最后一个元素，经过+1操作后比前面所有元素大即可
        # 此时子问题的最优解会收敛于全局最优解
        A.sort()
        count = 0
        for i in range(1, len(A)):
            if A[i] <= A[i - 1]:
                count += (A[i - 1] + 1) - A[i] # 改变后(即前一个值+1)的数值 - 原来的数值
                A[i] = A[i - 1] + 1
        return count
```