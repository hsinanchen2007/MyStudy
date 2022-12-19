```javascript
// @lc code=start
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
  let j = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] != 0) {
      [nums[j], nums[i]] = [nums[i], nums[j]]; //swap交换
      j++;
    }
  }
};
```

先定义一个指针j，循环原数组
假设数据是
[1,2,4,0,2]
当i = 3，也就是数字0的时候，j++这是也为3
i继续往后走，i=4的时候，j还是为3，因为nums[4]不为0，因此
nums[3]和nums[4]对调位置
如此反复即可