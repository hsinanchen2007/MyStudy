遍历单元格，计算每个格子的立方体叠成的表面积s = 底面+顶面+四周*n(当前立方体个数)，再根据周围是否有立方体以及有多少个立方体进行相减 s -= Math.min(currentLength, anotherLength);
```js
var surfaceArea = function(grid) {
    var count = 0;
    var r = grid.length;
    var c = grid[0].length;
    for(var i=0;i<r;i++){
        for(var j=0;j<c;j++){
            var temp = grid[i][j];
            if(temp > 0){
                count += 1 + 1 + temp * 4;
                if(j<c-1 && grid[i][j+1] > 0) count -= Math.min(temp, grid[i][j+1]);
                if(i<r-1 && grid[i+1][j] > 0) count -= Math.min(temp, grid[i+1][j]);
                if(i>0 && grid[i-1][j] > 0) count -= Math.min(temp, grid[i-1][j]);
                if(j>0 && grid[i][j-1] > 0) count -= Math.min(temp, grid[i][j-1]);
            }
        }
    }
    return count;
};
```