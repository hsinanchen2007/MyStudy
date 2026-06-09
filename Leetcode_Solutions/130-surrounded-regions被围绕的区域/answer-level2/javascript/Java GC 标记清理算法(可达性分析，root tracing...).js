### 解题思路
参考java GC回收过程常用的可达性分析算法。
即 
1. 找到GC Roots, 即必定不能回收的节点（在这儿是边界的'O'）
2. 从GC Roots出发，找到它们直接或间接引用的节点并加入队列，并对他们进行标记，它们也不能回收。在这儿是和边界‘O’连成一片的所有‘O’，并对他们进行标记成‘m’
3. 清除没有标记的内存对象。在这儿是把除‘m’之外的cell改成'X'
4. 重置，把标记('m')恢复成‘O’.

### 代码

```javascript

  /**
   * @param {string[][]} board
   * @return {void} Do not return anything, modify board in-place instead.
   */
  function solve(board) {
    if (board.length === 0) {
      return;
    }
    if (board[0].length === 0) {
      return;
    }
    const roots = getRoots(board);
    markFromRoots(roots, board);
    clearUnmarked(board);
  }

  function clearUnmarked(board) {
    const rows = board.length;
    const cols = board[0].length;
    for (let r = 0; r < rows; r++) {
      const row = board[r];
      for (let c = 0; c < cols; c++) {
        if (row[c] === 'O') {
          row[c] = 'X';
        } else if (row[c] === 'm') {
          row[c] = 'O';
        }
      }
    }
  }

  function getRoots(board) {
    const roots = [];
    const rows = board.length;
    const cols = board[0].length;
    for (let r = 0; r < rows; r++) {
      if (board[r][0] === 'O') {
        roots.push({r, c: 0});
      }
      if (board[r][cols - 1] === 'O') {
        roots.push({r, c: cols - 1});
      }
    }
    for (let c = 1; c < cols - 1; c++) {
      if (board[0][c] === 'O') {
        roots.push({r: 0, c});
      }
      if (board[rows - 1][c] === 'O') {
        roots.push({r: rows - 1, c});
      }
    }
    return roots;
  }

  function markFromRoots(roots, board) {
    while (roots.length > 0) {
      const root = roots.shift();
      board[root.r][root.c] = 'm';
      const left = getNode(board, root.r, root.c - 1);
      const right = getNode(board, root.r, root.c + 1);
      const top = getNode(board, root.r - 1, root.c);
      const bottom = getNode(board, root.r + 1, root.c);
      left === 'O' && roots.push({r: root.r, c: root.c - 1});
      right === 'O' && roots.push({r: root.r, c: root.c + 1});
      top === 'O' && roots.push({r: root.r - 1, c: root.c});
      bottom === 'O' && roots.push({r: root.r + 1, c: root.c});
    }
  }

  function getNode(board, r, c) {
    if (r >= 0 && c >= 0 && r < board.length && c < board[0].length) {
      return board[r][c];
    }
    return null;
  }


```