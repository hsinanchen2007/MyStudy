### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        A.sort()#进行排序
        m = 0#次数
        for i in range(0,len(A)):
            if A[i] <= A[i-1] #检查重复性，若有重复，次数加一
                m += (A[i-1]-A[i]+1) #重复区间
                A[i] = A[i-1]+1 #新的进行赋值，保证无重复
        return m

```