### 解题思路
* #### ex:
        [[1,10],
        [12,2]]
* #### 流程：
        1. 第一次循环,记录左上角的数值grid[0][0]
        2. 当i = 0时,开始遍历第一行所有的数,记录到没一格时获得的礼物价值
        3. 当i = 1时,考率上方的数字和左边的数字,哪一个可以提供更大的价值.
        4. 例如上述值为2的棋盘,需要考虑10+1和12+1,哪一个提供的价值更大
        5. 循环直至结束,输出右下角的数值,即为最大价值

### 代码

```py
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        for i in range(0,len(grid)):
            for j in range(0,len(grid[0])):
                left,up = 0,0
                if  i >0 :
                    up = grid[i-1][j]
                if j >0 :
                    left = grid[i][j-1]
                grid[i][j] += max(up,left)
        return grid[i][j]
```

*    保留原数组内容不变,需要额外O(N)的空间
```py
    '''不改变原数组: 影响下一个数的,只有数的前一个和上一个'''
class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        ans = [0 for _ in range( n)]
        for i in range(0, m):
            for j in range(0, n):
                left,up = 0,0
                if i > 0:
                    up = ans[j]
                if j > 0:
                    left = ans[j-1]

                ans[j] = max(up, left) + grid[i][j]
        return ans[j]


```