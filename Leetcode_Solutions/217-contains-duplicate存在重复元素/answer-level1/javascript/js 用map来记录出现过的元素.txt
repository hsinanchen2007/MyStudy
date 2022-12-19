### 解题思路
用完map之后发现用set更加简单明了了，基础还是不够牢啊

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 * 用map来记录
 */
var containsDuplicate = function(nums) {
    let map = new Map();
    for(let i=0; i<nums.length; i++){
        if(map.has(nums[i])) return true;
        map.set(nums[i],i)
    }
    return false;
};
```