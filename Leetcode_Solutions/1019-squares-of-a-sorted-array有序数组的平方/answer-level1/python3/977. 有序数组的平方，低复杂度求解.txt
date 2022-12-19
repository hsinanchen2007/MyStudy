### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        res = []
        i = 0
        while i < len(A) and A[i] < 0:
            i = i + 1
        flag = i - 1   # 查找正数与负数分界位置

        # 以flag为准线，向左向右比较数据，将小的数据入list        
        while flag >= 0 and i < len(A):
            if A[flag]**2 > A[i]**2:
                res.append(A[i]**2)
                i = i + 1
            else:
                res.append(A[flag]**2)
                flag = flag - 1
        print(res)
        # 将剩余的数据添加至list后面，即剩余的数据即为最大的数据
        while flag >= 0:
            res.append(A[flag]**2)
            flag = flag - 1
        print(res)
        while i < len(A):
            res.append(A[i]**2)
            i = i + 1
        return res
```