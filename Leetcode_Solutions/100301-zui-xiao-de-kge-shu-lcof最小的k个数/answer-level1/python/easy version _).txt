### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if not arr:
            return []
        if k == 0:
            return []
        re = sorted(arr)
        result = []
        for i in re:
            result.append(i)
            k = k - 1
            if k == 0:
                break
        return result 
        
```