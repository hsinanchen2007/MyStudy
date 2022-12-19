### 解题思路
```
执行用时 :3 ms, 在所有 Java 提交中击败了98.65%的用户
内存消耗 :41.3 MB, 在所有 Java 提交中击败了68.93%的用户
```
通过对一个个网格单位来进行处理。
1. 首先根据该单元格上是否存在立方体
2. 计算该单元格上立方体的表面积
3. 对单元格周围进行判断（重难点）。因为我们是一个个单元格依次计算，可以当作是一次次的叠加。判断其左侧和上侧的单元格是否存在立方体，如果存在，取两者最矮的那个（矮才重），然后计算重合面积（`*2`的原因）并减去。
4. 与累计值进行相加
### 代码

```java
class Solution{
    public int surfaceArea(int[][] grid) {
        int i, j;
        // 获取网格大小
        int size = grid[0].length;
        int temp;
        int sum = 0;
        for(i = 0; i<size; i++){
            for(j = 0; j<size; j++){
                if(grid[i][j] == 0) continue;
                temp = 2 + 4 * grid[i][j];
                // 判断其左侧是否存在立方体
                if ((i - 1) > -1) {
                    temp = temp - Math.min(grid[i - 1][j], grid[i][j]) * 2;
                }
                // 判断其上方是否存在立方体
                if((j - 1) > -1) {
                    temp = temp - Math.min(grid[i][j - 1], grid[i][j]) * 2;
                }
                sum += temp;
            }
        }        
        return sum;
    }
}
```
```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function (grid) {
  var sum = 0
  var temp
  var size = grid[0].length
  for (var i = 0; i < size; i++) {
    for (var j = 0; j < size; j++) {
      if (grid[i][j] === 0) continue
      temp = 2 + 4 * grid[i][j]
      // 判断其上侧是否存在立方体
      if ((i - 1) > -1) {
        temp = temp - Math.min(grid[i - 1][j], grid[i][j]) * 2
      }
      // 判断其左侧是否存在立方体
      if ((j - 1) > -1) {
        temp = temp - Math.min(grid[i][j - 1], grid[i][j]) * 2
      }
      sum += temp
    }
  }
  return sum
};
```