### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        arr = grid
        row = len(arr)
        col = len(arr[0])
        new_arr = [[0]*len(arr[0]) for i in range(len(arr))]
        for i in range(row):
            for j in range(col):
                if i-1>=0 and j-1>=0:
                    new_arr[i][j] = min(new_arr[i-1][j],new_arr[i][j-1])+arr[i][j]
                elif i==0:
                    if j==0:
                        new_arr[i][j] = arr[i][j]
                    else:
                        new_arr[i][j] = new_arr[i][j-1] + arr[i][j]
                elif j==0:
                    if i==0:
                        new_arr[i][j] = arr[i][j]
                    else:
                        new_arr[i][j] = new_arr[i-1][j] + arr[i][j]
        return (new_arr[-1][-1])
```