题目虽然没说，但是三角形的列数和行数应该是相等的，最开始就是很简单的开辟一个二维数组,由底部向上循环求解，每个位置的最小路径和。

![微信截图_20190524152643.png](https://pic.leetcode-cn.com/8eadff9b75c94c977143849b8a6795d77e2745f51a523e45e26b7625bde1f3bf-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190524152643.png)

可以看到，例如一个
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

最下一行，[4,1,8,3]的最小和就是其本身，

倒数第二行[6,5,7]  
其中6对应 4，1  
 5对应 1，8  
 7 对应 8，3.
因此每一层[i][j]对应的都是下一层的[i+1][j]和[i+1][j+1]

```
// 执行用时: 136 ms, 在Triangle的JavaScript提交中击败了18 .81 % 的用户
// 内存消耗: 34.8 MB, 在Triangle的JavaScript提交中击败了53 .09 % 的用户
// 直接底部向上dp 可以继续优化空间
var minimumTotal = function (triangle) {
  let h = triangle.length,
    l = triangle[h - 1].length;
  let temp = [];
  for (let i = 0; i < l; i++) {
    temp[i] = new Array(l).fill(0)
  }
  // console.log(temp)
  for (let i = h - 1; i >= 0; i--) {
    for (let j = 0; j <= l - (h - i); j++) {
      // 最后一列的值就是当前值
      if (i == l - 1) {
        temp[i][j] = triangle[i][j]
      } else {
        temp[i][j] = Math.min(temp[i + 1][j], temp[i + 1][j + 1]) + triangle[i][j]
      }
    }
  }
  // console.log(temp)
  return temp[0][0]
};
```

然后再次思索  每次从[i][0]开始更新的话，0对应的数据不会再被后续的路径覆盖。因此可以将开辟的二维数组简化为一维数组

```
// 执行用时: 84 ms, 在Triangle的JavaScript提交中击败了96 .04 % 的用户
// 内存消耗: 35.4 MB, 在Triangle的JavaScript提交中击败了12 .34 % 的用户
// 可以节省额外空间 
var minimumTotal = function (triangle) {
  let h = triangle.length,
    l = triangle[h - 1].length;
  let temp = new Array(l).fill(0);
  console.log(temp)
  for (let i = h - 1; i >= 0; i--) {
    for (let j = 0; j <= l - (h - i); j++) {
      // 最后一列的值就是当前值
      if (i == l - 1) {
        temp[j] = triangle[i][j]
      } else {
        temp[j] = Math.min(temp[j], temp[j + 1]) + triangle[i][j]
      }
    }
  }
  // console.log(temp)
  return temp[0]
};
```
