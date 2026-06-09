### 解题思路

#### 若目标元素不在原始数组中

* 目标元素小于第一个元素，返回索引0
* 目标元素大于最后一个元素，返回索引`nums.length`
* 目标元素在两元素之间，返回较大值索引

#### 若目标元素在原始数组中，返回目标元素索引

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    
};/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
  if(target < nums[0]) {
    return 0;
  } else if(target > nums[nums.length-1]) {
    return nums.length;
  } else {
    for(var i=0, len=nums.length; i<len; i++) {
      if(nums[i] == target) {
        return i;
      } else if(nums[i] < target && nums[i+1] > target) {
        return i+1;
      }
    }
  }
};

```