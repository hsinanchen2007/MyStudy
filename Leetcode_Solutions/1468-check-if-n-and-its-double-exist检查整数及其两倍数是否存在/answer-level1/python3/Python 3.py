### 解题思路
全部除以2 用in來找 暴力

### 代码

```python3
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        try:
            arr.remove(0)
        except:
            pass
        for i in arr:
            if i/2 in arr:
                return True
        return False
```