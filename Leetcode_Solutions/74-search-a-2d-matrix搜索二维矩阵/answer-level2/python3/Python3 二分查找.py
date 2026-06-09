### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if matrix == [] or matrix == [[]]:
            return False
        temp = []
        for mm in matrix:
            temp += mm
        i, j = 0, len(temp) - 1
        while i < j:
            mid = (i + j) >> 1;
            if temp[mid] < target:
                i = mid + 1
            else:
                j = mid
        return temp[j] == target
```

![image.png](https://pic.leetcode-cn.com/e1a8f2464c721339364de232ca821fa6e7039da51ae3ef3ac039f08a21b1dd0c-image.png)
