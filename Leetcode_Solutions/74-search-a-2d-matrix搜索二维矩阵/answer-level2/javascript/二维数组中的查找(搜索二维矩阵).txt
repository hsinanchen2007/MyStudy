### 解题思路
1.暴力破解
2.左下角遍历
3.二分
### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */

//暴力破解
function searchMatrix(matrix, target) {
  const len = matrix.length - 1;
  let isFind = false;
  for (let i = 0; i <= len; i++) {
    for (let j = 0, count = matrix[i].length - 1; j <= count; j++) {
      if (matrix[i][j] == target) {
        isFind = true;
        return isFind;
      }
    }
  }
  return isFind;
}

//需要从右上角或者左下角开始搜索，每一次判断可以排除一行或者一列。
//左下角
//假设所有列数都一致
//如果等于目标值返回
//如果大于目标值，当前行-1
//如果小于目标值，当前列+1
var searchMatrix = function(matrix, target) {
  if(matrix.length == 0){
      return false
  }
  const rows = matrix.length - 1;
  const cols = matrix[0].length;
  let row = rows;
  let col = 0;
  let isFind = false;
  while (row >= 0 && col < cols) {
    if (matrix[row][col] === target) {
      isFind = true;
      return isFind;
    }
    else if (matrix[row][col] > target) {
      row--;
    } else {
      col++;
    }
  }
  return isFind;
};

//二分查找法
//数据必须是有序，也就是说排好序
//用两个指针，一个指向第一个数，left = 0，一个指向最后一个数，right = arr.length - 1
//然后再取中位数，判断该中位数 arr[mid] 和目标值 target 的大小
//如果中位数刚好是需要找的那个数，直接返回索引mid
//如果大于目标值呢？目标值肯定在中位数前面，所z以缩小right边界，right = mid - 1
//如果小于目标值呢？目标值肯定在中位数后面，所以缩小left边界，left = mid + 1
//当left = right的时候，说明搜索范围已经是一个数了，不能再缩小了，再缩小就可以停止了。

var searchMatrix = function(matrix, target) {
  if (matrix.length === 0) {
    return false;
  }
  const rows = matrix.length - 1;
  const cols = matrix[0].length - 1;
  for (let i = 0; i <= rows; i++) {
    let left = 0;
    let right = cols;
    while (left <= right) {
      const mid = Math.floor((left + right) / 2);
      if (matrix[i][mid] === target) {
        return true;
      }
      if (matrix[i][mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
  }
  return false;
};
```
