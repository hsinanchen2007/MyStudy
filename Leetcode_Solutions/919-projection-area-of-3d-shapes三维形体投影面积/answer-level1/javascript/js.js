### 解题思路
顶部透视：非0的格子个数
yz面：固定j坐标，个数最多的会覆盖住因此其中最大值即为这一列投影面积，依次相加可得总面积
xz面同理，固定i坐标
由于N*N,所以循环条件都是小于N即可
### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var projectionArea = function(grid) {
    width=grid.length;
    //xy面投影面积
    let top=0;let side=0;let face=0;
    for(let i=0;i<width;i++){
        for(let j=0;j<width;j++){
            if(grid[i][j]!=0){
                top++;
            }
        }
    }
    //yz面投影面积从j轴计算固定j坐标最大值之和
    
    for(let i=0;i<width;i++){
        let max=0;
        for(let j=0;j<width;j++){
            max = grid[i][j]>max? grid[i][j]:max;
        }
        side+=max;
    }
    //xz面投影面积从i轴计算固定i坐标最大值之和
    let index=0;
    for(let j=0;j<width;j++){
        let max=0;
        for(let index=0;index<width;index++){
           max=grid[index][j]>max ? grid[index][j]:max; 
        }
        face+=max;
    }

    return face+side+top;
};
```