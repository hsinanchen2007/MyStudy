### 解题思路
直接使用python中的sorted函数，在进行切片操作就可以得出相应结果

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        a =sorted(arr)
        return a[:k]
```