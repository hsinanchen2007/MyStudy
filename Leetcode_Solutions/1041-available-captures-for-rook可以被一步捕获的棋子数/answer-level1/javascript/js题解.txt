```
var numRookCaptures = function(board) {
  // 车的坐标
  let centerlocal = [];
  // 上右下左方向标量
  let directionX = [0, 1, 0, -1];
  let dirextionY = [1, 0, -1, 0];
  // 卒的数量
  let pCount = 0;
  // 找到车的坐标
  for (let x = 0; x < 8; x++) {
    for (let y = 0; y < 8; y++) {
      if (board[x][y] === "R") {
        centerlocal = [x, y];
        break;
      }
    }
  }
  // 遍历四个方向
  for (let d = 0; d < 4; d++) {
       let dx = centerlocal[0]
      let dy = centerlocal[1];
    while (true) {
      dx = directionX[d] + dx;
      dy = dirextionY[d] + dy;
      if (dx < 0 || dy < 0 || dx > 7 || dy > 7 || board[dx][dy] === "B"){
        break
      };
      if (board[dx][dy] === "p"){
        pCount++;
        break
      }
    }
  }
  return pCount;
};
```
