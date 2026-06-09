### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    let arr = [];
    for (let i = 0; i < nums.length; i++) {
        if (arr[nums[i]] == undefined) {
            arr[nums[i]] = 1;
        } else {
            return nums[i];
        }
    }
};
```