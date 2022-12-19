## 方法：一遍遍历

每行、每列、每个子数独，都用一个哈希表来存放该行、该列、该子数独已经有的元素（共3\*9个哈希表）。遍历每个元素，判断它在其所在行、列、子数独哈希表中是否已经存在，存在则返回False。

```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_table, col_table, sub_tabel = [{} for _ in range(9)], [{} for _ in range(9)], [{} for _ in range(9)]
        for i in range(9):
            for j in range(9):
                item = board[i][j]
                if item == ".": continue
                sub_idx = 3 * (i // 3) +  (j // 3)
                if item in row_table[i] or item in col_table[j] or item in sub_tabel[sub_idx]:
                    return False
                row_table[i][item] = 1
                col_table[j][item] = 1
                sub_tabel[sub_idx][item] = 1
        return True
```

**复杂度分析：**

* 时间复杂度：O(1) （数据规模为81）
* 空间复杂度：O(1)（数据规模为81）
