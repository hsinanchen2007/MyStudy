### 解题思路
1. 将数组转换为坐标，看作，x 行，y 列上的 z 值，举例：[[2]] 也就可以第 0 行，0 列上的 z 值为 2。
2. 通过三层遍历，就可以拿到所有 z 值，计算出所有立方体的表面积。
3. 接下来删去相邻立方体的面就可以啦。
4. 通过坐标把立方体周围的六个立方体坐标拿到 const around = [[x-1,y,z],[x,y+1,z],[x+1,y,z],[x,y-1,z],[x,y,z-1],[x,y,z+1]];
5. 遍历 around 的六个点，grid[item[0]][item[1]] 有效后得到的值就是实际上 x,y 位置的 z 值，如果该 z 值大于 around 中的 z 值，则该面相邻，表面积减1.
6. 结束！
7. 实际结果内从消耗较大，但该方法可能好理解。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
    let area = 0;
    for(let x = 0; x < grid.length; x ++){
        for(let y = 0; y < grid[x].length; y++){
            for(let z = 0; z < grid[x][y]; z++){
                area+=6; // 所有立方体提交和
                const around = [[x-1,y,z],[x,y+1,z],[x+1,y,z],[x,y-1,z],[x,y,z-1],[x,y,z+1]]; // 立方体周围六个立方体的坐标
                around.forEach((item)=>{
                    if(grid[item[0]] instanceof Array&&
                    grid[item[0]][item[1]]>-1&&
                    item[2]>-1&&
                    grid[item[0]][item[1]] > item[2] // 相邻立方体是否存在
                    ){
                        area-=1; // 减去相邻的面
                    }
                });
            }
        }
    }
    return area;
};
```