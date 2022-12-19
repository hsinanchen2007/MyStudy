### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        arr_list=list(set(arr))
        arr_count=[arr.count(i) for i in arr_list]
        return arr_list[arr_count.index(max(arr_count))]

```