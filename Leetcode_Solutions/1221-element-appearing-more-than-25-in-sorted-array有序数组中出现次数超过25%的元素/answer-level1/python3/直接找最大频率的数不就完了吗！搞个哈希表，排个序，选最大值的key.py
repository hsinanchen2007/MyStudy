### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        from collections import Counter
        dic = Counter(arr)
        return sorted(dic, key = dic.get)[-1]
```