### 解题思路
使用计数器，遍历各元素的次数，判断是否满足条件。

### 代码

```python3
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        dico = collections.Counter(arr)
        for i, j in dico.items():
            if j > len(arr)/4: return i
```