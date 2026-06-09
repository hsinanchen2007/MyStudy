### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        count = 0
        for i in range(1,len(A)):
            if A[i] <= A[i-1]:
                count += A[i-1]-A[i]+1
                A[i] = A[i-1]+1
        return count

```



the very nice method for this problem

贪心算法，排序后按规定排列为最小值