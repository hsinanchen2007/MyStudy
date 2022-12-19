### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
  let row = grid.length,
      col = grid[0].length;
  let time = 0;
   
  let map = new Map(); // key是腐烂的橘子的一维坐标，value是腐烂的时间
  let queue = []; // 存储值为2的节点
  
  for (let r = 0; r < row; r++) {
    for (let c = 0; c < col; c++) {
      // 第一遍先遍历所有初始为2的橘子
      // 并转化为一维数组中的位置并存储
      if (grid[r][c] === 2) {
        let code = r * col + c;
        queue.push(code);
        map.set(code, 0);
      }
    }
  }
  
  let tmpArr = [[0, -1], [1, 0], [0, 1], [-1, 0]];
  
  while (queue.length !== 0) {
    let code = queue.shift();
    let c = code % col,
        r = Math.floor(code / col);
    for (let i = 0; i < 4; i++) {
      let newr = r + tmpArr[i][0],
          newc = c + tmpArr[i][1];
      if (newr >= 0 && newr < row && newc >= 0 && newc < col && grid[newr][newc] === 1) {
        grid[newr][newc] = 2;
        let newcode = newr * col + newc;
        queue.push(newcode);
        map.set(newcode, map.get(code) + 1);
        time = map.get(newcode);
      }
    }
  }
  
  for (let r = 0; r < row; r++) {
    for (let c = 0; c < col; c++) {
      if (grid[r][c] === 1) {
        return -1;
      }
    }
  }
  
  return time;
};
```