### 解题思路

遍历找出只出现一次的数字

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function(nums) {
    const { length } = nums;
    let res = {};
    for(let i = 0; i < length; i++){
        if (res[nums[i]] !== undefined) {
            delete res[nums[i]];
        } else {
            res[nums[i]] = nums[i];
        }
    }
    return Object.values(res);
};
```