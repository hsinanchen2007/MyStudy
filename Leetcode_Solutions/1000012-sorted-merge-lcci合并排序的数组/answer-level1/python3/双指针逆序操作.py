### 解题思路
双指针，逆向排序。选当前最大的排到最后，不影响A中的数据。当A还剩元素时，不需要操作。当B还剩元素时，需拷贝过去

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i = m - 1
        j = n - 1
        last = m + n - 1
        while last >= 0 and j >= 0 and i >= 0:
            if A[i] < B[j]:
                A[last] = B[j]
                j -= 1
            else:
                A[last] = A[i]
                i -= 1
            last -= 1
        if j >= 0:
            A[:j+1] = B[:j+1]
        
```

![image.png](https://pic.leetcode-cn.com/ac3114999519c4f4d0b4bc0414cab16a5f1c5316a3bdd4087183954490869d91-image.png)
