### 解题思路
每一行的结果由数组的原本的结果取得:从倒数第二项开始往前运算

### 代码

```python3
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        row = [None for _ in range(rowIndex + 1)]
        for i in range(rowIndex + 1):
            row[i] = 1
            j = i
            while j >= 2:
                row[j - 1] = row[j-1] + row[j - 2]
                j -= 1
        return row
```