### 解题思路
遍历一遍，使用Map存储原始值的最新下标，当遇到重复的value，比较下标差是否不大于k即可

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    const map = new Map();
    for(let i = 0,n = nums.length;i<n;i++){
        if(map.has(nums[i]) && i-map.get(nums[i])<=k){
            return true
        }
        map.set(nums[i],i)
    }
    return false;
};
```