

```js

var maxAreaOfIsland = function(grid) {
    let m = grid.length;
    //1空数组返回0  
    if(m === 0) return 0;
    //2二维空数组返回0  
    let n = grid[0].length;
    if(n ===0) return 0;
    let result = 0
    for(let i =0 ; i < m ; i++){
        for(let j = 0 ; j < n ; j++){
            //3遍历数据，排除grid[i][j]===0的海水
            if(grid[i][j] === 1){
                //4递归 找当前岛屿上下左右相邻是否是岛屿 
               const temp =  helper(i,j)
               result = Math.max(result,temp)
            }
        }
    }
    //
   function helper(i,j){
       if(i===m || i < 0){
           return 0
       }else if(j === n || j < 0){
           return 0
       }
       if(grid[i][j] === 1){
        grid[i][j] = 0;  //6 遍历的元素，修改元素值，避免不必要的遍历
    //5如果是岛屿，递归 
           return 1+helper(i+1,j)+helper(i,j+1)+helper(i-1,j)+helper(i,j-1)
       }
       return 0
    }
    return result
    console.log(result)
};
```
