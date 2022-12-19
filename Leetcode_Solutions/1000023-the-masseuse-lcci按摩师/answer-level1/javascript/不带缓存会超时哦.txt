### 解题思路

递归 + cache

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    const cache = {};
    function f(i) {
        if (cache[i] !== undefined) return cache[i];
        if (i < 0) return 0;
        const rel= Math.max(f(i - 1), f(i - 2) + nums[i]);
        cache[i] = rel;
        return rel;
    }
    return f(nums.length - 1);
};


```