### 解题思路
- 排序后遍历列表
- if cur<pre,cur = pre + 1; move = move + 增量；
- 增量的计算：更新后的值-更新前的值，更新之前计算（pre+1 - cur），避免cur更新以后丢失cur的旧值。 
### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()
        L = len(A)
        index = 1
        res = 0
        while index<L:
            if A[index]<=A[index-1]:
                res = res + (A[index-1]+1-A[index])
                A[index]=A[index-1]+1
            index+=1
        return res
            
            
```