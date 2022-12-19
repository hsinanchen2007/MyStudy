# 第一版，找规律交换数字位置
> 64ms,34.2M。
## 代码
```javascript []
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
  const maxIndex = matrix.length - 1;
  let newLoc = {
    1: (row, col) => ({ row: col, col: maxIndex - row }),
    2: (row, col) => ({ row: maxIndex - row, col: maxIndex - col }),
    3: (row, col) => ({ row: maxIndex - col, col: row }),
  };

  for (let i = 0; i < matrix.length / 2; i++) {
    for (let j = i; j < maxIndex - i; j++) {
      let temp = matrix[i][j];
      let row = i;
      let col = j;
      for (let k = 3; k > 0; k--) {
        const { row: newRow, col: newCol } = newLoc[k](i, j);
        matrix[row][col] = matrix[newRow][newCol];
        row = newRow;
        col = newCol;
      }
      matrix[row][col] = temp;
      // console.log(i,j);
      // console.table(matrix)
    }
  }
};
```
## 思路
![$8Q{0G8NCG`\]Y9E3VQJLJ0J.png](https://pic.leetcode-cn.com/ac7c9edad29ff768b56fcc86bb1baeb5be14e74a48610ce8cccf2cafc7be588c-$8Q%7B0G8NCG%60%5DY9E3VQJLJ0J.png)
- 对于人类来说在脑海中完成上图的变换很容易，但是如果要让代码理解的话必须要告诉代码每一次变换时各个数字的坐标。我将上图中红色箭头组成的环视为一次旋转90°变换。那么将图像旋转90°可以认为是n个不同的环各旋转90°。
- 关键在于两个部分
  1. ### **找出每一次旋转中四个点的坐标**
    + 将4个点从左上部分开始按顺时针顺序标记为点0，点1，点2，点3。知道点0的坐标时可以得到另外三个点坐标与点0坐标的关系如下（输入参数为点0坐标，分别返回点1，点2，点3坐标）
      ```javascript
      let newLoc = {
          1: (row, col) => ({ row: col, col: maxIndex - row }),
          2: (row, col) => ({ row: maxIndex - row, col: maxIndex - col }),
          3: (row, col) => ({ row: maxIndex - col, col: row }),
        };
      ```
    + 旋转部分代码如下。
      1. (i, j)为旋转起始点坐标
      2. 将点0值用临时变量保存
      3. 依次将点3数值赋给点0，点2数值赋给点3，点1数值赋给点2，临时变量即原点0数值赋给点1
      ```javascript
      let temp = matrix[i][j];
      let row = i;
      let col = j;
      for (let k = 3; k > 0; k--) {
        let { row: newRow, col: newCol } = newLoc[k](i, j);
        matrix[row][col] = matrix[newRow][newCol];
        row = newRow;
        col = newCol;
      }
      matrix[row][col] = temp;
      ```
  2. ### **找出有多少个需要旋转的环**
    + 可以转化为找出有多少个环的起点，如下图中红色框中的点即为对应宽度为3、4的图形需要旋转的环起始点，下方循环代码的i，j即各个起始点的坐标
    + ![)9H~TX(`_7)90@~\[3~ITNSB.png](https://pic.leetcode-cn.com/9305068c211ff41bd0b5d0390102d7c80f11750349406e318fc95667f38bf63e-\)9H~TX\(%60_7\)90@~%5B3~ITNSB.png)

      ```javascript
        for (let i = 0; i < matrix.length / 2; i++) {
          for (let j = i; j < maxIndex - i; j++) {
          }
        }
      ```


