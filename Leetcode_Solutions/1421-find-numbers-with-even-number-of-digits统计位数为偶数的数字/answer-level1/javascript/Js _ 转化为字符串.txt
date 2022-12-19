### 解题思路
将nums的元素转化成字符串，再拆分成数组，取其length求余，返回total计数

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function (nums) {
  let total = 0;
  for (let i = 0; i < nums.length; i++) {
    let arr = nums[i].toString();
    if (arr.length % 2 === 0) {
      total ++;
    }
  }
  return total
};
```
//reduce
// var findNumbers = function (nums) {

//   return nums.reduce((pre, cur) => {
//     return (cur.toString().length % 2 === 0 ? 1 : 0) + pre
//   }, 0)

// };