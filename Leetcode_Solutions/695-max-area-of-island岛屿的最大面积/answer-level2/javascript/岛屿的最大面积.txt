代码清析明了，从起始点开始查找，起始点置0，从起始点上下左右四个方法逐个查找
```
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    let count = 0;
    let result = 0;
    let search = (i,j)=>{
        //原点
        if(grid[i] && grid[i][j]){
            console.log('--原--',grid[i][j])
            count ++;
            grid[i][j] = 0;//查找过的就置0
        }
        //上
        if(grid[i-1] && grid[i-1][j]){
            console.log('--上--',grid[i-1][j])
            search(i-1,j);
        }
        //右
        if(grid[i] && grid[i][j+1]){
            console.log('--右--',grid[i][j+1])
            search(i,j+1);
        }
        //下
        if(grid[i+1] && grid[i+1][j]){
            console.log('--下--',grid[i+1][j])
            search(i+1,j);
        }
        //左
        if(grid[i] && grid[i][j-1]){
            console.log('--左--',grid[i][j-1])
            search(i,j-1);
        }
    }
    for(let i = 0;i<grid.length;i++){
        for(let j =0;j<grid[i].length;j++){
            if(grid[i][j]){                
                console.log('--search--',i,j)
                search(i,j);
            }
            console.log(count);
            if(count > result){result = count}
            count = 0;
        }
    }
    return result
};
```
