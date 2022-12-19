![image.png](https://pic.leetcode-cn.com/3421607069d6c484900adc674300c32b0f73c89f2147c07da90bde81fe235b64-image.png)

### 解题思路
```js
直观思路：只要在每一行遇到了负数，那么从他往后都是负数
```

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */

var countNegatives = function(grid) {
  let rowLimit = grid.length,
      ans = 0;
  
  for (let i = 0; i < rowLimit; i++) {
    let row = grid[i];
    for (let j = 0; j < row.length; j++) {
      if (row[j] < 0) {
        ans += row.length - j;
        break;
      }
    }
  }
  
  return ans;
};
```