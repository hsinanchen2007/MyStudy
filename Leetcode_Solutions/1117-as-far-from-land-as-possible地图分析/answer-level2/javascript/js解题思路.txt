### 解题思路
执行用时 :108 ms, 在所有 JavaScript 提交中击败了92.50% 的用户
内存消耗 :41.9 MB, 在所有 JavaScript 提交中击败了100.00%的用户

此题思路与腐烂的橘子一样
将初始陆地坐标放进队列，然后逐次取出队列坐标，判断其上下左右是否有海洋，有则将海洋的值改为11，放进队列，第一轮结束后距离加一；之后每轮都是一样的操作，直至队列没有元素

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function(grid) {
    let [ queue_1, maxDistance] = [ [], -1]
    for(let i = 0; i < grid.length; i++){
        for(let j = 0; j < grid[0].length; j++){
            if(grid[i][j] == 1)
                queue_1.push([i, j])
        }        
    }
    if(queue_1.length == (0 || (grid.length*grid[0].length))) return -1
    while(queue_1.length != 0){
        let len = queue_1.length;
        for(let k = 0; k < len; k++){
            let [i1, j1] = queue_1.shift();
            if(i1 > 0 && grid[i1-1][j1] == 0){
                grid[i1-1][j1] = 1;
                queue_1.push([i1-1,j1]);
            }
            if(i1 < grid.length - 1 && grid[i1+1][j1] == 0){
                grid[i1+1][j1] = 1;
                queue_1.push([i1+1,j1]);
            }
            if(j1 > 0 && grid[i1][j1-1] == 0){
                grid[i1][j1-1] = 1;
                queue_1.push([i1,j1-1]);
            }
            if(j1 < grid[0].length - 1 && grid[i1][j1+1] == 0){
                grid[i1][j1+1] = 1;
                queue_1.push([i1,j1+1]);
            }
        }
        maxDistance++;
    }
    return maxDistance;
};
```