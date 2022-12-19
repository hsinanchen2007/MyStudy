### 解题思路
![image.png](https://pic.leetcode-cn.com/eb58a24bdc7af1624787b7053890c0e1bc0063ae368b5ea39d549b7204d6eacd-image.png)
![image.png](https://pic.leetcode-cn.com/b5032d346fd5f91216689e75ae0e0af163de463328b9c393a3a52f0ca3a7f8fa-image.png)

-本质上是一个 Z字 轮换

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */
var shiftGrid = function(grid, k) {
    xL=grid[0].length-1; 
    yL=grid.length-1; 

    for(let q=0;q<k;q++){
        let lastItem = grid[yL][xL];
        for(let y=yL;y>=1;y--){
          grid[y].splice(xL,1);
        grid[y].unshift(grid[y-1][xL])
        }
         grid[0].splice(xL,1);
        grid[0].unshift(lastItem)
    }
    return grid;
};

```