### 解题思路
也是看了题解后，才知道能用%和~~(/) 来获取二维坐标。能够将二维坐标一维化，我觉的是很重要的一点，以为一维化后，就能进行标识是否是坏的。唉！第一次听这个BFS(不是计算机专业的，对于一些算法还是很陌生)。

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    var dir_x = [0,1,0,-1] //用来获取左右坐标，只要x,y错开就可以。
    var dir_y = [1,0,-1,0] // 用来获取上下坐标
     var r = grid.length;
     var c = grid[0].length; 
     var  queue = [];
     var time ={};
     var cont = 0;
     var sumtime = 0;
     for (var i = 0;i<r;i++){
         for(var j = 0;j<c;j++){
             if(grid[i][j] === 2){
                 var code = i*c+j
                 queue.push(code);
                 time[code] = 0;
             }else if(grid[i][j] === 1){
                 cont++;
             }
         }
     }
     while(queue.length !== 0){
         var now = queue.shift();
         var prey = ~~(now/c);
         var prex = now%c;
         for(var k =0;k<4;k++){
             var currx = prex + dir_x[k];
             var curry = prey + dir_y[k];
           if(currx < c && currx>=0 && curry>=0&& curry<r && grid[curry][currx] === 1){
               grid[curry][currx] = 2
               var code = curry*c+currx;
               queue.push(code);
               time[code] = time[now] + 1;
               cont--;
               sumtime = time[code];
           }
         }
     }
    return cont ? -1 : sumtime;
};
```