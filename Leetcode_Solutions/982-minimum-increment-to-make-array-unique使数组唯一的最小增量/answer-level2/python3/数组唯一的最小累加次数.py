### 解题思路
将数组排序后，使每个小于前一个数据的元素累加至唯一即可

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        num = 0
        for i in range(1,len(A)):
            if(A[i]<=A[i-1]):
                num+=A[i-1]-A[i]+1
                A[i]=A[i-1]+1
        return num
```