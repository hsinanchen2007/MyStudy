JS实现
```js
/* eslint-disable max-len */
/* eslint-disable no-bitwise */
class Step {
  constructor(i, j, keybit, step) {
    this.i = i;
    this.j = j;
    this.keybit = keybit;
    this.step = step;
  }
}


/**
 * @param {string[]} grid
 * @return {number}
 */
const shortestPathAllKeys = function (grid) {
  const M = grid.length;
  const N = grid[0].length;
  const LOWER_A = 'a'.charCodeAt(0);
  const UPPER_A = 'A'.charCodeAt(0);
  let KEY_BIT = 0;

  // find start & all keys
  let start = null;
  for (let i = 0; i < M; i += 1) {
    for (let j = 0; j < N; j += 1) {
      const cur = grid[i][j];
      if (cur === '@') {
        start = [i, j];
      } else if (cur >= 'a' && cur <= 'f') {
        KEY_BIT |= 1 << (cur.charCodeAt(0) - LOWER_A);
      }
    }
  }

  const visited = new Array(M);
  for (let i = 0; i < M; i += 1) {
    visited[i] = new Array(N);
    for (let j = 0; j < N; j += 1) {
      visited[i][j] = {};
    }
  }
  visited[start[0]][start[1]][0] = true;

  const directions = [
    [-1, 0],
    [1, 0],
    [0, 1],
    [0, -1],
  ];

  const queue = [new Step(start[0], start[1], 0, 0)];
  while (queue.length !== 0) {
    const cur = queue.shift();
    if (cur.keybit === KEY_BIT) {
      return cur.step;
    }
    for (let d = 0; d < directions.length; d += 1) {
      const nextI = cur.i + directions[d][0];
      const nextJ = cur.j + directions[d][1];
      if (nextI >= 0 && nextI < M && nextJ >= 0 && nextJ < N && !visited[nextI][nextJ][cur.keybit]) {
        const nextChar = grid[nextI][nextJ];
        if (nextChar >= 'a' && nextChar <= 'f') {
          const nextKeyBit = cur.keybit | (1 << (nextChar.charCodeAt(0) - LOWER_A));
          queue.push(new Step(nextI, nextJ, nextKeyBit, cur.step + 1));
          visited[nextI][nextJ][cur.keybit] = true;
          visited[nextI][nextJ][nextKeyBit] = true;
        } else if (
          nextChar === '.'
          || nextChar === '@'
          || (nextChar >= 'A' && nextChar <= 'F' && cur.keybit & (1 << (nextChar.charCodeAt(0) - UPPER_A)))
        ) {
          queue.push(new Step(nextI, nextJ, cur.keybit, cur.step + 1));
          visited[nextI][nextJ][cur.keybit] = true;
        }
      }
    }
  }
  return -1;
};

```
