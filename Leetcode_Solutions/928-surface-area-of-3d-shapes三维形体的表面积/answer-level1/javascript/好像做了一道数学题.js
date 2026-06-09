### 解题思路
拆分为两部分，一是顶和底area1，二是侧面area2
当grid[i][j]不为空时，area1一定为2
当grid[i][j]不为空时，该位置上的侧面积是grid[i][j]*4，再考虑grid[i][j+1]和grid[i+1][j]上被重叠掉的部分即可

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var surfaceArea = function(grid) {
//包含顶 底 侧面
let area1=0,area2=0;
 let coverNum=0;
for(let i=0;i<grid.length;i++){
    for(let j=0;j<grid[0].length;j++){
        if(grid[i][j]!=0){
            //顶 底
            area1=area1+2;
            //侧
            area2=area2+4*grid[i][j];          
            if(i+1<grid.length){
                coverNum=grid[i][j]<grid[i+1][j]?grid[i][j]:grid[i+1][j];
                area2=area2-coverNum*2;
            }
            if(j+1<grid[0].length){
                coverNum=grid[i][j]<grid[i][j+1]?grid[i][j]:grid[i][j+1];
                area2=area2-coverNum*2;
            }
        }
           

    }
}
return area2+area1;

};
```