### 解题思路
对数组进行排序，如果是单调序列，排序后的数组必定为原序列或者逆序列
### 代码

```python
class Solution(object):
    def isMonotonic(self, A):
        A_copy = A
        A_copy = sorted(A_copy)
        if A_copy == A or A_copy == A[::-1]:
            return True
        else:
            return False
```