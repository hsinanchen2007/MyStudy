### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let obj = {};
    let len = nums.length;
    for (let i = 0; i < len; i++) {
        let diff = target - nums[i];
        if (obj[diff] >=0 ) {
            return [obj[diff], i];
        }
        obj[nums[i]] = i;
    }
};
```