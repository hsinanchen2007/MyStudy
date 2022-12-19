### 解题思路
此处撰写解题思路
    使用a.sort()也可。这里使用带有返回值的sorted()。
### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        arr = sorted(arr)
        return arr[:k]
```