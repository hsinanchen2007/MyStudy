### 解题思路
在偶数位置判断奇偶性。

### 代码

```python
class Solution(object):
    def sortArrayByParityII(self, A):
        odd = 1
        for i in range(0, len(A), 2):
            if A[i] % 2:
                while A[odd] % 2:
                    odd += 2
                A[i], A[odd] = A[odd], A[i]
        return A
```
### 结果200ms，排名93%