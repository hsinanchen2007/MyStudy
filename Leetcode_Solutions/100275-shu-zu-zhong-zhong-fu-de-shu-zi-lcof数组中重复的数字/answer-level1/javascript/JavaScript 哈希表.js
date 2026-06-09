### 解题思路
简单的哈希表，超过一个就返回

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    let hash = {}
    for(let i in nums) {
        if (hash[nums[i]]) return nums[i]
        hash[nums[i]] = 1
    }
};
```