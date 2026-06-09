js ： 记录方块的总数，每个方块6个面，再减掉方块之间互相贴合而损失的面积

顺便说一句，这玩意是“飘”在天上的，不用减地面那部分面积

```js
var surfaceArea = function(grid) {
  const N = grid.length;
  if(N === 0)return 0;

  let num = 0;//方块数量
  let area = 0;//方块之间互相贴合损失的面积数
  
  for(let i=0;i<N;i++){
    for(let j=0;j<N;j++){
      let height = grid[i][j];

      if(height > 0){
        num += height; //累加方块数量
        area += (height-1)*2; //上下之间贴合的面积
         //前后左右按正视图看
        area += i>0 ? Math.min(height,grid[i-1][j])*2: 0;//左右之间贴合的面积
        area += j>0 ? Math.min(height,grid[i][j-1])*2: 0;//前后之间
      }
    }
  }
  return num*6 - area;
};
```
