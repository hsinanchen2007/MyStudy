### 解题思路
简洁

### 代码

```python3
class Solution:
    def search(self, arr: List[int], target: int) -> int:
        try:
            return arr.index(target)
        except:
            return -1
        
```