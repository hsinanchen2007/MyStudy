### 解题思路
上面兩個函式用來遍歷列表
之後簡單的用abs()來對照

### 代码

```python3
def __AT(list1):  # Array traversal
    for each in range(len(list1)):
        if isinstance(list1[each], list):
            for each2 in AT(list1[each]):
                yield each2
            continue
        yield list1[each]


def AT(list1):
    r = []
    for each in __AT(list1):
        r.append(each)
    return r
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        grid = AT(grid)
        counter = 0
        for i in range(len(grid)):
            if grid[i] != abs(grid[i]):
                counter += 1
        return counter
```