### 解题思路

解题的思路很清晰，就是先计算每个坐标上立方体表面积（在存在两个及以上时，第一个和最后一个都是5个表面积，中间的是四个表面积），然后减去由于相邻的坐标存在立方体会重叠的表面积，结果就是最终的表面积。

注意：相邻坐标重叠的表面积是2个表面相重叠，会失去2个表面积。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    let gl = grid.length;
    if (!gl) return 0;
    let count=0;
    for (let i=0;i<gl;i++){
        let gl1 = grid[i].length;
        if (!gl1) return 0;
        for (let j=0;j<gl1;j++){
            let temp = grid[i][j];
            if (temp >1){
                count =count + 10 + (temp-2)*4;
            }else {
                count = count + temp * 6;
            }
            if (j+1<gl1){
                count = count-2*Math.min(temp,grid[i][j+1]);
            }
            if (i+1<gl){
                count = count-2*Math.min(temp,grid[i+1][j]);
            }
        }
    }
    return count;
};
```

### 效果

![表面积题解图.png](https://pic.leetcode-cn.com/733ba60c939cfa1b29438bc9818d43b29343598ddccf68cf5fb1b5aa307572bc-%E8%A1%A8%E9%9D%A2%E7%A7%AF%E9%A2%98%E8%A7%A3%E5%9B%BE.png)