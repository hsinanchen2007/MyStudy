方法一、DFS
```
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    var count =0;
    for(var i=0;i<grid.length;i++){
        for(var j=0;j<grid[0].length;j++){
            if(grid[i][j] == '1' ){
                count++;
                dfs(grid,i,j);
            }
        }
    }
    return count;
};
function dfs(grid,i,j){
    //边界条件
    if(i<0 || i>=grid.length || j<0 || j>=grid[0].length || grid[i][j]!= '1'){
        return;
    }else{
        //已经被搜索过的标记为‘2’
        grid[i][j] = '2';
        dfs(grid,i+1,j);//四个方向遍历
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
}
```
方法二、BFS
```
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    var directions = [[-1,0],[1,0],[0,-1],[0,1]]
    var count =0;
    for(var i=0;i<grid.length;i++){
        for(var j=0;j<grid[0].length;j++){
           if(grid[i][j] == '1'){
               //数组模拟队列
               var arr = [];
               arr.push(i * (grid[0].length) + j);
               //将遍历过的陆地标记为‘2’
               grid[i][j]=='2';
               while(arr.length>0){
                   //shift()函数返回移除的首元素，以该元素为中心向四个方向搜索
                   var str = arr.shift();
                   var curX = Math.floor(str/(grid[0].length));
                   var curY = str % (grid[0].length);
                   for(var k=0;k<4;k++){
                       var newX = curX + directions[k][0];
                       var newY = curY + directions[k][1];
                       if(newX>=0 && newX<grid.length && newY>=0 && newY<grid[0].length && grid[newX][newY]=='1'){
                           arr.push(newX * (grid[0].length) + newY);
                           grid[newX][newY]='2';
                       }
                   }
               }
               count++;
           }
        }
    }
    return count;
};
```

