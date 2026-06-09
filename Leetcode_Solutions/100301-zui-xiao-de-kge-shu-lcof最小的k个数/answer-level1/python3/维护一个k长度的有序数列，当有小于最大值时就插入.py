### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if k == 0: return []
        ans = arr[:k]
        ans.sort()
        for i in range(k, len(arr)):
            if arr[i]<ans[-1]:
                ans[-1] = arr[i]
                ans.sort()
        return ans
```