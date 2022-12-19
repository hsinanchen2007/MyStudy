### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    let obj = {};
    let arr = [];
    for(let i = 0; i< nums.length; i++) {
        if (obj[nums[i]]) {
            arr.push(nums[i]);
        } else {
            obj[nums[i]] = true;
        }
    }
    return arr[0];
};
```