### 解题思路
set去重，sorted排序兼copy，zip成大小排序序号的字典，按原arr顺序输出，记得加1

### 代码

```python3
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        arr2=list(sorted(set(arr)))
        dic = dict(zip(arr2,range(len(arr2))))
        return [dic[i]+1 for i in arr]
```