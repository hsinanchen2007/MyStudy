### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if k == 0 or k > len(arr) or not arr:
            return []
        else:
            return sorted(arr)[:k]
```