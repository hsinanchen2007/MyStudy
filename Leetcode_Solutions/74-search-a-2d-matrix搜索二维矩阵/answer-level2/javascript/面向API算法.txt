### 解题思路
此处撰写解题思路

执行用时 :
68 ms
, 在所有 JavaScript 提交中击败了
66.34%
的用户
内存消耗 :
34.3 MB
, 在所有 JavaScript 提交中击败了
100.00%
的用户
### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    return matrix.some((item)=>item.some(sitem=>sitem==target));
};
```