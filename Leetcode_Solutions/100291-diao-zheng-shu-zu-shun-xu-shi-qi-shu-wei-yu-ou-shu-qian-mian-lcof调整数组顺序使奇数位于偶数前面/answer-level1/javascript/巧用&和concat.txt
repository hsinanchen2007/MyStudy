### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var exchange = function(nums) {
  let arr = [];
  let doubleArr = [];
  for(let i=0;i<nums.length;i++){
      if(nums[i]&1) {
          arr.push(nums[i]);
      } else {
          doubleArr.push(nums[i]);
      }
  }
  return arr.concat(doubleArr);
};
```