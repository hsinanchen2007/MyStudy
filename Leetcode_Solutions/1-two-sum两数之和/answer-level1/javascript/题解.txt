### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
        let index = target - nums[i]
        if (map.has(nums[i])) {
            return [map.get(nums[i]), i]
        }
        map.set(index, i);
    }

};
```
