### 解题思路
从后往前比较，后面比较过的数可以被覆盖，时间复杂度是O(m+n)

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        p_a = m-1
        p_res = m+n-1
        while(B):
            b_last = B.pop()
            while(p_a>=0 and A[p_a]>b_last):
                A[p_res] = A[p_a]
                p_res -= 1
                p_a -= 1
            A[p_res] = b_last
            p_res -= 1

        
            
```