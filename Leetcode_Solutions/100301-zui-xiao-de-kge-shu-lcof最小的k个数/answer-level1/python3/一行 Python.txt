### 解题思路
将数组排序，返回前 k 项即可。
### 代码

```python []
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        return sorted(arr)[:k]
```
### 复杂度分析

- 时间复杂度：$O(NlogN)$，使用了排序。
- 空间复杂度：$O(1)$。