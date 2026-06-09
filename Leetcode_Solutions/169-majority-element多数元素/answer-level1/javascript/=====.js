### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    let obj = {}
    let numberOfTimes = nums.length / 2
    for (let i = 0; i < nums.length; i++) {
        if (obj.hasOwnProperty(nums[i])) {
            obj[nums[i]]++
        } else {
            obj[nums[i]] = 1
        }
    }
    for (let key in obj) {
        if (obj[key] > numberOfTimes) {
            return key
        }
    }
};
```