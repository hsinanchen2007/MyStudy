### 解题思路
所谓贪心算法，就是每次求得局部最优解，在这里就是每次使得相邻的两个数不重复
之所以在比较的时候使用 >= ，是因为当有多个重复的时候，可能会出现前面move之后比后面大的情况。

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        count = 0
        for i in range(1,len(A)):
            if A[i-1] >= A[i]:
                count += A[i-1] - A[i] + 1
                A[i] = A[i-1] + 1
        return count

```