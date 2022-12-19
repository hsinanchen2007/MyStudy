### 解题思路
对整个矩阵中的每个元素进行遍历，如果其为陆地，计算其四周为陆地的个数 k，则其提供的周长为 4-k
全部累加起来即可。

这里遍历整个二维矩阵的计算复杂度太高了, 如果利用仅有一个岛，可以减小搜索空间



[求一半的思路](https://leetcode-cn.com/problems/island-perimeter/solution/qiu-yi-ban-ji-ke-by-danvychan/)稍微比我的方法精简一点，但复杂度仍然是一样的。
由于已知都是矩形块，且中间没有湖。只需求出整个岛朝向北的周长以及朝向东的周长加起来再乘以 2 即可。


### 代码

```python3
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:

        m = len(grid)
        if m == 0:
            return
        n = len(grid[0])
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]
        result = 0
        for i in range(m):
            for j in range(n):  # 这里计算复杂度太高了, 如果利用仅有一个岛，可以减小搜索空间
                if grid[i][j] == 1:
                    val = 4  # 本来应该是 4， 但可能被其他陆地遮盖
                    for k in range(4):
                        nx, ny = i+dx[k], j+dy[k]
                        if 0<=nx<m and 0<=ny<n:
                            val -= (grid[nx][ny]==1)  # 若为1， 则减少1
                    result += val
        return result


```