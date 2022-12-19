### 解题思路
时间复杂度：O（n2）
空间复杂度：O（n2）

### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        if numRows == 1:
            return [[1]]
        all_list = self.generate(numRows-1)
        num_list = []
        for i in range(numRows):
            if i == 0:
                num_list.append(1)
            elif i == numRows - 1:
                num_list.append(1)
            else:
                num_list.append(all_list[-1][i-1] + all_list[-1][i])
        all_list.append(num_list)
        return all_list

```