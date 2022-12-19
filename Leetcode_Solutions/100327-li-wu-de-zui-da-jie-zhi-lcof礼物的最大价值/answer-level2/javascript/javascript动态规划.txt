```
var maxValue = function(grid) {
  for(let i=0;i<grid.length;i++){
    for(let j=0;j<grid[0].length;j++){
      if(i==0&&j==0) continue;
      if(i===0) grid[i][j]=grid[i][j-1]+grid[i][j];
      if(j===0) grid[i][j]=grid[i-1][j]+grid[i][j];
      if(i!==0&&j!==0) grid[i][j]=Math.max(grid[i-1][j],grid[i][j-1])+grid[i][j]
    }
  }
  return grid[grid.length-1][grid[0].length-1]
};
```
