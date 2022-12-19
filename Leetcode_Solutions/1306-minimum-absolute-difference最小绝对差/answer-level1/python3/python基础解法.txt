### 解题思路
首先排序，然后求出所有的差值，再反查等于最小值的组合。

### 代码

```python3
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr = sorted(arr)
        differ  = [ (arr[i+1]-arr[i]) for i in range(len(arr)-1)]
        min_value = min(differ)
        result = [[arr[k],arr[k+1]] for k,v in enumerate(differ) if v ==min_value]
        return result
        

```