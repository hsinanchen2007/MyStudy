### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function (nums) {
    let obj = {}
    let result = []
    for (let i = 0; i < nums.length; i++) {
        if (obj.hasOwnProperty(nums[i])) {
            obj[nums[i]]++
        } else {
            obj[nums[i]] = 1
        }
    }
    for (let key in obj) {
        if (obj[key] == 2) {
            result.push(key)
        }
    }
    return result
};
```