### 解题思路
普通循环思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    let map = {}, len = nums.length, result
    for (let i = 0; i < len; i++) {
        if (map[nums[i]] !== undefined) {
            map[nums[i]] += 1
        } else {
            map[nums[i]] = 1
        }
        if (map[nums[i]] > len / 2) {
            result = [nums[i]]
            break
        }
    }
    return result
};
```