```javascript
/*
 * @lc app=leetcode.cn id=15 lang=javascript
 *
 * [15] 三数之和
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number[][]}
 */

/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var threeSum = function(nums) {
  nums = nums.sort((a, b) => a - b); //  先排序,升序
  let r = 0; //边界r初始为0
  let arr = [];  //接收结果的数组
  while (nums[r] <= 0) { //如果边界r大于0则结束
    let j = nums.length - 1;
    let i = r + 1; 
    while (nums[r] === nums[r + 1]) r ++;  //去重操作
    while (i < j) {
      //如果两数之和小于-r，则左推进，反之右推进
      if (nums[i] + nums[j] === -nums[r]) {
        arr.push([nums[i], nums[r], nums[j]]);
        while (nums[i] === nums[i + 1]) i++; //去重操作
        while (nums[j] === nums[j - 1]) j--; //去重操作
        i++; 
        j--;
      } else if (nums[i] + nums[j] < -nums[r]) {
        i++;
      } else {
        j--;
      }
    }
    r++;
  }
  return arr;
};
// @lc code=end

```
