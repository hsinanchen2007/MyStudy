### 解题思路
如果数组长度为0，1 ，2 ，则必然单调。
否则判断一下是否单调递增或单调递减即可。

### 代码

```python3
class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        if len(A) < 3: return True
        return  all(A[i]-A[i-1] >= 0 for i  in range(1,len(A))) or \
                all(A[i]-A[i-1] <= 0 for i  in range(1,len(A)))
        

```