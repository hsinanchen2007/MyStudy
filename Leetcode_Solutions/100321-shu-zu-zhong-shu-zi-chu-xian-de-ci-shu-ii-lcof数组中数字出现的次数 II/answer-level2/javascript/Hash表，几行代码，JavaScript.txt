### 解题思路
和上一题基本一样，只是多了个if判断而已

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    const len = nums.length;
    let hash = {};
    for(let i = 0; i < len; i ++) {
        if(hash[nums[i]] === undefined) {
            hash[nums[i]] = 1;
        } else if (hash[nums[i]] === 1) {
            hash[nums[i]] = 2;
        } else if (hash[nums[i]] === 2) {
            delete hash[nums[i]];
        }
    }
    for(let i in hash) {
        return i;
    }
};
```