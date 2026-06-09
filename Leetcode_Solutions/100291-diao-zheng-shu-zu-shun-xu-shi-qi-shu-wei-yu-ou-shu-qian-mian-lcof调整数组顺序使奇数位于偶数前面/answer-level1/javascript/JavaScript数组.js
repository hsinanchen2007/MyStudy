### 解题思路

数组

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var exchange = function(nums) {
    const leftArr = [], rightArr = []
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] % 2 !== 0) { // 是奇数
            leftArr.push(nums[i])
        } else {
            rightArr.push(nums[i])
        }
    }
    return [...leftArr, ...rightArr]
};
```