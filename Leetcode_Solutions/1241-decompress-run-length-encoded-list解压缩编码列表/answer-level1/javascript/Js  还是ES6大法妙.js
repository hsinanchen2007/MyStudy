### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function (nums) {
  res = []
  for (var i = 0; i < nums.length; i += 2) {
    for (var j = 0; j < nums[i]; j++) {
      res.push(nums[i + 1]);
    }
  }
  return res;
};

// @xch1029的ES6方法学习: 
// Array.fill() 固定值替换数组元素

// var decompressRLElist = function(nums) {
//     let result = []
//     for(let i = 0; i < nums.length / 2; i+=1) {
//         result = [...result, ...new Array(nums[2*i]).fill(nums[2*i+1])]
//     }
//     return result
// };

```