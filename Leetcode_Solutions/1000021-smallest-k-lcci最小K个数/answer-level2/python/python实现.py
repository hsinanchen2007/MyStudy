### 解题思路
此处撰写解题思路
在本题可以先排序，然后在排序好的列表中选取数字即可
### 代码

```python3
class Solution:
    def smallestK(self, arr: List[int], k: int) -> List[int]:
        li = sorted(list(arr))
        num = int(k)
        if k>0:
            return li[:num]
        else:
            return []
```