## 解法一：递归解
> 通过了48个测试用例，在第49个用例报错栈溢出
```javascript []
/**
 * @param {number} N
 * @param {number[][]} mines
 * @return {number}
 */
var orderOfLargestPlusSign = function(N, mines) {
  let max = 0;
  const grid = [];
  for (let i = 0; i < N; i ++) {
    grid[i] = new Array(N).fill(1);
  }

  for (let i = 0; i< mines.length; i ++) {
    grid[mines[i][0]][mines[i][1]] = 0;
  }

  const kObj = {};

  const maxK = (x, y, z = 'max') => {
    if (kObj[`${x}${y}`] && kObj[`${x}${y}`][z] > 0) return kObj[`${x}${y}`];
    kObj[`${x}${y}`] = { l: 0, r: 0, u: 0, d: 0, max: 0 };

    if (grid[x][y] !== 0) {
      kObj[`${x}${y}`].u = x === 0 ? 1 : maxK(x - 1, y, 'u').u + 1;
      kObj[`${x}${y}`].d = x === N - 1 ? 1 : maxK(x + 1, y, 'd').d + 1;
      kObj[`${x}${y}`].l = y === 0 ? 1 : maxK(x, y - 1, 'l').l + 1;
      kObj[`${x}${y}`].r = y === N - 1 ? 1 : maxK(x, y + 1, 'r').r + 1;
      kObj[`${x}${y}`].max = Math.min(kObj[`${x}${y}`].u, kObj[`${x}${y}`].d, kObj[`${x}${y}`].l, kObj[`${x}${y}`].r);
    }
    return kObj[`${x}${y}`];
  }
  for (let i = 0; i < N; i ++) {
    for (let j = 0; j < N; j ++) {
      max = Math.max(max, maxK(i, j).max);
    }
  }

  // console.log(kObj);
  return max;
};
```
### 思路
1. 矩阵中每个节点四个方向上的加号臂长都可以分解成该节点在这个方向上邻节点的同方向臂长值加1
2. 遇到节点值为0则将四个方向臂长设为1
3. 遇到矩阵边界上的节点则将对应方向的臂长设为0
4. 使用一个对象记录所有节点的臂长，减少递归过程中的重复计算
5. 最下面的循环看起来有问题，可以优化

自己的方法一失败后又不想再用暴力解写一次了，所以去看看其他大佬的题解

## 方法二：循环
### 方法来自[题解](https://leetcode-cn.com/problems/largest-plus-sign/solution/xiang-xi-de-guo-cheng-si-lu-by-user1428i/)
### 思路：循环矩阵一次，每次循环可以按顺序计算四个不同节点的对应单一方向的臂长
* 刚开始我也想到了可以按顺序计算每个节点的单一方向臂长，四个方向各循环一次就可以解决。
* 然后我又想到了可以同时计算同一个节点的两个方向臂长，只需要循环两次即可。。
* 没有往一次计算多个节点的方面去考虑。`╮(╯▽╰)╭`