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
    for (let i = 0; i < nums.length;i++) {
        if (typeof obj[nums[i]] == 'number') {
            return [obj[nums[i]], i];
        }
        obj[target-nums[i]] = i;
    }
};
```