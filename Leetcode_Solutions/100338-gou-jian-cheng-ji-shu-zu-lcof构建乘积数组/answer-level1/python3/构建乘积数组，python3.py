### 解题思路
先从左往右累乘，再从右往左累乘

### 代码

```python3
class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        res = [1 for i in a]
        left = [1 for i in a]
        right = [1 for i in a]
        for i in range(len(a)):
            left[i] *= a[i]
            if i > 0:
                left[i] *= left[i-1]
        
        for j in range(len(a)-1, -1, -1):
            right[j] *= a[j]
            if j < len(a)-1:
                right[j] *= right[j+1]
            if j == len(a)-1:
                res[j] = left[j-1]
            elif j == 0:
                res[j] = right[1]
            else:
                res[j] = left[j-1]*right[j+1]
        return res
```