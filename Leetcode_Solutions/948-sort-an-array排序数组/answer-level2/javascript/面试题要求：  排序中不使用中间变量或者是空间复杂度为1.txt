### 解题思路

在双循体中，将赋值操作给予  j+1； 然后连减进行赋值；

或者是单独使用函数方法： [a, b] = [b, a];

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    for(let i = 0; i < nums.length; i++) {
        for(let j = 0; j < nums.length - 1- i; j ++) {
            if (nums[j] > nums[j + 1]) {
                nums[j +1]= nums[j] + nums[j+1];
                nums[j] = nums[j+1] -nums[j];
                nums[j +1] = nums[j+1] - nums[j]
            }
        }
    }
    return nums;
};
```