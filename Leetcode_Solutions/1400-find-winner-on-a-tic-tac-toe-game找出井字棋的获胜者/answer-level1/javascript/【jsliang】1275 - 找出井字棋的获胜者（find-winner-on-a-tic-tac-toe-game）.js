这道题，在我编写五子棋的游戏中也碰到过。

当初老师教的是暴力编写，所以你懂的：

> 暴力破解

```js
/**
 * @name 判断矩阵
 * @param {*} matrix 需要判断的矩阵
 */
const judge = (matrix) => {
  const [
    p1, p2, p3,
    p4, p5, p6,
    p7, p8, p9,
  ] = [
    matrix[0][0], matrix[0][1], matrix[0][2],
    matrix[1][0], matrix[1][1], matrix[1][2],
    matrix[2][0], matrix[2][1], matrix[2][2],
  ]
  // 1. 判断横排
  if (p1 === p2 && p2 === p3) {
    return p1;
  } else if (p4 === p5 && p5 === p6) {
    return p4;
  } else if (p7 === p8 && p8 === p9) {
    return p7;
  }
  // 2. 判断竖排
  if (p1 === p4 && p4 === p7) {
    return p1;
  } else if (p2 === p5 && p5 === p8) {
    return p2;
  } else if (p3 === p6 && p6 === p9) {
    return p3;
  }
  // 3. 判断斜排
  if (p1 === p5 && p5 === p9) {
    return p1;
  } else if (p3 === p5 && p5 === p7) {
    return p3;
  }
  return 'Draw'; // 无结局
};

/**
 * @name 找出井字棋的获胜者
 * @param {number[][]} moves
 * @return {string}
 */
const tictactoe = (moves) => {
  // 1. 填充九宫格为 NaN，NaN !== NaN
  const matrix = Array.from(Array(3), () => Array.from(Array(3), () => NaN));
  // 2. 遍历 moves 命令进行填充
  for (let i = 0; i < moves.length; i++) {
    const x = moves[i][0];
    const y = moves[i][1];
    if (i % 2 === 0) {
      matrix[x][y] = 'A';
    } else {
      matrix[x][y] = 'B';
    }
  }
  // 3. 返回最终结果
  const result = judge(matrix);
  if (moves.length < 9 && result === 'Draw') {
    return 'Pending';
  } else {
    return result;
  }
};
```

步骤如下：

1. 设计九宫格元素都为 `NaN`。这里需要强调的是，我们设置 `NaN` 是因为 `NaN !== NaN`。
2. 遍历 `moves` 命令，对矩阵 `matrix` 进行填充。这里需要注意的是，我们填充 `'A'` 或者 `'B'`，并不需要最后再判断是 `'X'`/`'O'`。
3. 然后就是通过 `judge` 方法暴力判断矩形，分别列举横排、竖排和斜排的情况即可。
4. 最后就是 `Draw` 状态和 `Pending` 状态需要进行区分。

搞定收工，Submit 提交：

```js
Accepted
* 100/100 cases passed (64 ms)
* Your runtime beats 76.38 % of javascript submissions
* Your memory usage beats 54.17 % of javascript submissions (33.9 MB)
```

当然，如果小伙伴们有更好的思路想法，欢迎评论留言或者私聊 **jsliang**~


公众号：飘飞的心灵

GitHub：https://github.com/LiangJunrong/document-library