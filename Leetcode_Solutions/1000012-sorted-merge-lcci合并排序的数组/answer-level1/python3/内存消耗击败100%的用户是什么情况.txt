### 解题思路
执行用时 :
36 ms, 在所有 Python3 提交中击败了89.15%的用户
内存消耗 :
13.5 MB, 在所有 Python3 提交中击败了100.00%的用户

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """

        # 首先想到的是双指针。modify A in-place instead.
        a = 0
        b = 0

        for i in range(len(A)):
            if b == n:
                break
            if a == m:
                A[0:n-b] = B[0:n-b]
                break
            
            if A[-n-1-a] >= B[-1-b]:
                A[-1-i] = A[-n-1-a]
                a += 1
            else:
                A[-1-i] = B[-1-b]
                b += 1
        
            
        

            
            


```