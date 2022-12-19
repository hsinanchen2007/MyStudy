### 解题思路

时间复杂度：O(n)
空间复杂度：O(n)

### 代码

执行用时 : 64 ms , 在所有 Python3 提交中击败了 94.59% 的用户
内存消耗 : 23.8 MB , 在所有 Python3 提交中击败了 100.00% 的用户

```python3
class Solution:
    def constructArr(self, A: List[int]) -> List[int]:
        if not A: return []
        forward = [1]
        for a in A[:-1]:
            forward.append(forward[-1]*a)
        
        backward = [1]
        for a in A[::-1][:-1]:
            backward.append(backward[-1]*a)
        backward = backward[::-1]
        
        B = [f*b for f, b in zip(forward, backward)]
        return B
```

