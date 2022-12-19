### 解题思路
1. 首先，对于本道题，你要先理清题意，能将它的题中的意思形象化，例如，输入`[[1,2],[3,4]]`,我们可以将其写为如下形式：
![1111.PNG](https://pic.leetcode-cn.com/f14e8f89b235111b819a59cc986d1753da61725cffe5da1ff9b1aeb091e16de7-1111.PNG)
图中每个数字都代表当前位置上的折叠的立方体数目
2. 我们可以先求出总的立方体面数，然后减去重复的面数，最后得到的就是最终的表面积
### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    // 定义保存最后的总的面数的变量sum
    let sum = 0
    // 遍历二维数组
    for (let i=0; i<grid.length; i++) {
        for (let j=0; j<grid[i].length; j++) {
            if (grid[i][j] != 0) { // 若当前位置的立方体数目不为0，则可求得当前位置所折叠的立方体的所有面数和
                // 最上和最下面的两个立方体，各有5个面暴露在外面，中间的立方体只有四个面暴露
                sum += (grid[i][j] - 2) * 4 + 10
            }
            if (i > 0) {
                // 列
                let col = grid[i-1][j] > grid[i][j] ? grid[i][j] : grid[i-1][j]
                sum -= col * 2
            }
            if (j > 0) {
                // 行
                let row = grid[i][j-1] > grid[i][j] ? grid[i][j] : grid[i][j-1]
                sum -= row * 2
            }
        }
    }
    return sum
};
```