![image.png](https://pic.leetcode-cn.com/998dcd74f475987d04ebd39ee434ca2346cb4af2d1393d54e210bcdb5f91a641-image.png)

### 解题思路
```js
思路：

我们遍历去尝试 N 皇后的位置时，采用逐行尝试的方式，尝试完第一行、尝试第二行、
第三行。。。 这样，所以我们不用记录当前行是否可以放置，行是不会重复的。
我们只需要记录放置过皇后的点，它的同列、对角线不可放置即可

需要的方法：
1.判断当前位置是否可以放置
2.放置皇后之后设置该点的同列、对角线不可放置
3.清除该点的皇后，设置该点的同列、对角线为可放置
4.把找到解法的数组转换为题目要求的格式的方法
  比如：[1,3,0,2] => [".Q..","...Q","Q...","..Q."]

总结同列以及同对角线的特性，看看在尝试解的过程中，怎么去判断当前位置
是否可以尝试？
我自己定义的标记：
undefined： 为可以放置
1： 为该点已放置，它的同列、对角线不可放置

同列：列数相同
同对角线：
  - 左对角线 '/' ：两个点的 列数 + 行数 相等
  - 右对角线 '\' ：两个点的 列数 - 行数 相等

开撸。。代码
```

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[][]}
 */

var solveNQueens = function(n) {
  let ans = [],
      col_list = [],
      left_line = [],
      right_line = [];
  
  function isCanSet(row, col) {
    return col_list[col] === undefined && left_line[col + row] === undefined && right_line[col - row] === undefined;
  }
  
  function setCanSet(row, col) {
    col_list[col] = undefined;
    left_line[col + row] = undefined;
    right_line[col - row] = undefined;
  }
  
  function setCanNotSet(row, col) {
    col_list[col] = 1;
    left_line[col + row] = 1;
    right_line[col - row] = 1;
  }
  
  function solve(arr) {
    let solution = [];
    for (let row = 0; row < arr.length; row++) {
      let c = arr[row], temp = '';
      for (let col = 0; col < n; col++) {
        if (col === c) {
          temp += 'Q';
        } else {
          temp += '.';
        }
      }
      solution.push( temp );
    }
    ans.push( solution );
  }
  
  function dfs(curr, currow) {
    if (curr.length === n) {
      solve( curr ); // 拼装解法放到答案数组中
      return ;
    }
    
    for (let i = currow; i < n; i++) {
      for (let j = 0; j < n; j++) {
        if (isCanSet( i, j )) {
          curr.push( j );
          setCanNotSet(i, j);
          dfs(curr, i + 1);
          curr.pop();
          setCanSet(i, j);
        }
      }
    }
  }

  dfs([], 0);
  
  return ans;
};
```