### 解题思路
算出对应当前第x个分别在新旧矩阵中的行列位置即可
![566. Reshape the Matrix.png](https://pic.leetcode-cn.com/9af405c052b6227cb37a384ccef2505ba9654dcf360fc3bf6f81d34638f63d35-566.%20Reshape%20the%20Matrix.png)

### 代码

```javascript
/**
 * @param {number[][]} nums
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function (nums, r, c) {
  if (r * c !== nums.length * nums[0].length) {
    return nums;
  }
  const res = Array(r);
  let index = 0;
  for (let i = 0; i < r; i++) {
    res[i] = Array(c).fill(0);
    for (let j = 0; j < c; j++) {
      index = i * c + j; // 第 x 个
      res[i][j] = nums[Math.trunc(index / nums[0].length)][index % nums[0].length] // 对应新矩阵中 i,j 对应在旧矩阵中的位置
    }
  }
  return res;
};
```