### 解题思路
完全按照示例的思路，先把最大的排好

### 代码

```python3
class Solution:
    def pancakeSort(self, A: List[int]) -> List[int]:
        ans = []
        def help(A):
            max_num = max(A)
            min_num = min(A)
            if len(A) == 1:
                return ans
            elif max_num == A[-1]:
                return help(A[:-1])
            elif min_num == A[-1] or max_num == A[0]:
                ans.append(len(A))
                A = list(reversed(A))
                return help(A)
            else:
                for i in range(len(A)):
                    if A[i] == max_num:
                        break
                A[:i+1] = A[i::-1]
                ans.append(i+1)
                return help(A)
        return help(A)
```