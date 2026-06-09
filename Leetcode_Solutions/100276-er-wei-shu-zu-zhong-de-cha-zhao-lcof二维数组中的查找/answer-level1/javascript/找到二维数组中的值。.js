### 解题思路
因为从左右到右增序，从上到下增序，所以取左下角的那一个开始循环，如果小于就到上一个，如果大于就到右边。
还有一种解法就是暴力遍历两次循环进行查找。
### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    let index = matrix.length -1;
    let subIndex = 0;
    while(index>=0 && subIndex<matrix[0].length) {
        if(matrix[index][subIndex] == target) return true;
        if(matrix[index][subIndex] > target) {index--;continue;}
        if(matrix[index][subIndex] < target) {subIndex++;continue;}
     }
     return false;
};
```
