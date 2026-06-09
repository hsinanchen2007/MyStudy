贪心算法在于每个子问题的局部最优解会指向全局最优解。
显然在对数组排序之后，可以通过保证数组的最后一个元素，经过+1操作后比前面所有元素大即可,此时子问题的最优解会收敛于全局最优解
```python
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        # 贪心算法
        A.sort()
        count = 0
        for i in range(1, len(A)):
            if A[i] <= A[i - 1]:
                count += A[i - 1] - A[i] + 1
                A[i] = A[i - 1] + 1
        return count
```