### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findLucky(self, arr: List[int]) -> int:
        arr = sorted(arr,reverse = True)
        adi = {}
        for i in arr:
            if i in adi:
                adi[i] += 1
            else:
                adi[i] = 1
        for i in adi:
            if i == adi[i]:
                return i
        return -1
```