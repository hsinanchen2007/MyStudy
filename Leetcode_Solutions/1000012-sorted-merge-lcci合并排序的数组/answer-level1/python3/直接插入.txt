### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        cur = 0
        for b in B:
            while cur < m and A[cur] <= b:
                cur += 1
            # print(cur, b)
            if cur < m:
                A.insert(cur, b)
                A.pop()
                cur += 1
                m += 1
            else:
                A.insert(cur, b)
                A.pop()
                cur += 1
                
```