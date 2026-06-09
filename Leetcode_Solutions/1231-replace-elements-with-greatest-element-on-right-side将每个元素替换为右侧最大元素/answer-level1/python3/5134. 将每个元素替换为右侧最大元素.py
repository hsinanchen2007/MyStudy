### 解题思路
逆序比较会更方便一点

### 代码

```python3
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        max1 = arr[-1]
        res = [-1]
        for i in range(len(arr)-1,0, -1):
            max1 = max(max1, arr[i])
            res.append(max1)
        return res[::-1]
```