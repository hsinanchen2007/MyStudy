### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortArrayByParityII(self, A: List[int]) -> List[int]:
        
        n  = len(A)  
        s = 0 
        ans = n * [None]
        for i in range(n):
            if A[i] % 2 == 0:
                ans[s] = A[i]
                s += 2  
        t = 1 
        for i in range(n):
            if A[i] % 2 == 1:
                ans[t] = A[i]
                t += 2

        return ans  

```
2次遍历，先放偶数，再放奇数