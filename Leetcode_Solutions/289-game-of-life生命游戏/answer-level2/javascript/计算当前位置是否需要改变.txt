### 解题思路

当前坐标周围进行求和，判断是否需要改变。

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
const gameOfLife = board => {
  let map = deepClone(board);
  let _length_x = map.length;
  let _length_y = map[0].length;
  for (let y = 0; y < _length_y; y++) {
    for (let x = 0; x < _length_x; x++) {
      let shouldChange = isChangeOrNot(map[x][y], countAround(x, y, map)); // 是否需要改变
      // 位运算 0^true =>1, 1^true =>0
      if(shouldChange){
        board[x][y] = board[x][y] ^ shouldChange;
      }
    }
  }
};

// 判断是否需要改变
function isChangeOrNot(current, count) {
  let res = false;
  if (current) {
    // current is 1
    if (count < 2) res = true; // 死亡
    if (count > 3) res = true;
  } else {
    // current is 0
    if (count === 3) res = true;
  }
  return res;
}

// 地图周围求和
function countAround(x, y, map) {
  let count = 0;
  let _max_x = map.length;
  let _max_y = map[0].length;
  if (y > 0) {
    // 计算y-1行的count，先计算正上方
    count += map[x][y - 1]; // map(x,y)，地图方向不影响结果
    if (x > 0) {
      count += map[x - 1][y - 1];
    }
    if (x < _max_x - 1) {
      count += map[x + 1][y - 1];
    }
  }
  if (y < _max_y - 1) {
    // 计算y+1行
    count += map[x][y + 1];
    if (x > 0) {
      count += map[x - 1][y + 1];
    }
    if (x < _max_x - 1) {
      count += map[x + 1][y + 1];
    }
  }
  if (x > 0) {
    count += map[x - 1][y];
  }
  if (x < _max_x - 1) {
    count += map[x + 1][y];
  }
  return count;
}

// 深度clone
function deepClone(obj) {
  let _obj_copy = obj instanceof Array ? [] : {};
  for (let key of Object.keys(obj)) {
    if (typeof obj[key] !== "object") _obj_copy[key] = obj[key];
    else _obj_copy[key] = deepClone(obj[key]);
  }
  return _obj_copy;
}

```