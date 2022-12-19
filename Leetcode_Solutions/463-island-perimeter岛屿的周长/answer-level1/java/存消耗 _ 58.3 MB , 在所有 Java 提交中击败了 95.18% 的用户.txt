### 解题思路
1, 找规律：对于某一块陆地（地图上取值为1的点），最终边长的贡献值为4-上点取值-下点取值-左点取值-右点取值；
2，边界保护：如果直接在原数组上遍历，上下左右的边界异常考虑复杂，所以new出数组，然后上下左右一圈补零，从新数组1开始遍历到新数组长度-1停止；

### 代码

```java
class Solution {
    public int islandPerimeter(int[][] grid) {
        int[][] tmpdata = new int[grid.length+2][grid[0].length+2];
        for (int i = 1; i<=grid.length; ++i) {
            for (int j = 1; j <=grid[0].length; ++j) {
                tmpdata[i][j]=grid[i-1][j-1];
            }
        }

        int restult = 0;
        for (int i = 1; i <= grid.length; ++i) {
            for (int j = 1; j <= grid[0].length; ++j) {
                if (tmpdata[i][j] == 1) {
                    restult += 4-tmpdata[i-1][j]-tmpdata[i+1][j]-tmpdata[i][j+1]-tmpdata[i][j-1];
                }
            }
        }
        return restult;
    }
}
```