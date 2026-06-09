### 解题思路
![image.png](https://pic.leetcode-cn.com/ed652f0f4eac09097d70c8f596708cc4ef3d0b3125e853bd17886a4d6205d3e4-image.png)

比较容易理解的动态规划实现是构造一个和grid大小相同dp数组，用来记录每个位置的最优解，最后返回dp[-1][-1]的值即为解。

在此基础上尝试简化dp数组，构造dp_rows和dp_cols，保存遍历每一行，每一列的值即可。

### 1. 初始化

![image.png](https://pic.leetcode-cn.com/b305a73f7fbeac316dc62d7f1021eec60010433cc7d3a4ca858bcd2b812627f7-image.png)

由于只能向下和向右移动，第0行为例，每一个位置都是由**左边的相邻位位置状态转换**而成，同理第0列向下遍历。

### 2. 全局遍历

![image.png](https://pic.leetcode-cn.com/b1b17620fe0cb84218b5f4b8502797106988f882aef947dd8173c37dcae4098e-image.png)

随后对每一行，每一列进行遍历，即遍历第1行，第1列，再遍历第2行，第2列，依次类推。

由于只采用维度为1的数组来节省空间，还需要解释，如：`
dp_rows[2] = max(dp_rows[2], dp_row[1]) + grid[rows][2]`, 等式右边的`dp_row[1]`表示的是黑色框处状态值，属于`rows=1`时的遍历结果，`dp_rows[2]`表示的是绿色框处状态值，属于`rows=0`时的遍历结果，即上一轮，此处实现了**原地赋值**。

### 3. 边界取值

![image.png](https://pic.leetcode-cn.com/8a31d21488fb9c056e52d6612dd62f6b3ab3987f20c6585dcc22da870e61955c-image.png)

在上面的图示中，我们取了grid的长为6个单元格，宽为5个单元格，即rows将在cols之前遍历完。

蓝色的区域表示当前位置的最优解已经得到，而最后一个位置，将在`rows=cols=4`时遍历完成，此时返回`dp_rows[-1]`得到最优解。

**到此为止，就结束啦，再放上代码**。


### 代码

```python3
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:

        def initial(rows, cols):
            dp_rows = [0] * cols
            dp_cols = [0] * rows
            dp_rows[0] = grid[0][0] # first place in game
            dp_cols[0] = grid[0][0]
        
            # first row
            for i in range(1, cols):
                dp_rows[i] = dp_rows[i-1] + grid[0][i]
            # first col
            for j in range(1, rows):
                dp_cols[j] = dp_cols[j-1] + grid[j][0]

            return dp_rows, dp_cols


        def traverse_grid(dp_rows, dp_cols, rows, cols):
            # travers grid
            cur_rows = 1
            cur_cols = 1

            while cur_rows < rows and cur_cols < cols:
                # first place in dp_rows and dp_cols
                dp_rows[cur_rows] = max(dp_rows[cur_rows], dp_cols[cur_cols]) + grid[cur_rows][cur_cols]
                dp_cols[cur_cols] = dp_rows[cur_rows]
                # update dp_rows
                for i in range(cur_cols, cols-1):
                    dp_rows[i+1] = max(dp_rows[i], dp_rows[i+1]) + grid[cur_rows][i+1]
                # update dp_cols
                for j in range(cur_rows, rows-1):
                    dp_cols[j+1] = max(dp_cols[j], dp_cols[j+1]) + grid[j+1][cur_cols]

                cur_rows += 1
                cur_cols += 1

            # check if the all rows or cols has been traverse， and return the value
            if cur_rows == rows:
                return dp_rows[-1]
            else:
                return dp_cols[-1]

        # main
        rows = len(grid)
        if rows == 0: return 0 
        cols = len(grid[0])
        dp_rows, dp_cols = initial(rows, cols)
        return traverse_grid(dp_rows, dp_cols, rows, cols)
        
```