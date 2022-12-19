
```
var shiftGrid = function(grid, k) {
    let x = grid.length;
    let y = grid[0].length; 
    for (let i = 0; i < k; i++) {li
        let temp = [] //保存最后一列值
        temp.push(grid[x - 1][y - 1]);    // 将最后一列最后一个元素存入临时数组
        grid[x - 1].splice(y - 1, y);    // 同时删去刚刚存入的元素
        for (let j = 0; j < x - 1; j++) {   // 遍历二维数组的最后一列
            temp.push(grid[j][y - 1]);     
            grid[j].splice(y - 1, y);       
            grid[j].unshift(temp[j]);       
        }
        grid[x - 1].unshift(temp[x - 1]);
    }
    return grid;
};
```
