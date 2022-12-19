### 解题思路
一个对比，set.has 跟 array.indexOf 对比 时间差很多。。。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    let set = new Set(nums)
    let ans = 0
    for (let i in nums) {
        let cur = nums[i]
        if (!set.has(cur - 1)) {
            let len = 1
            while(set.has(cur + 1)) {
                cur = cur + 1
                len++
            }
            ans = Math.max(ans, len)
        }
    }
    return ans
};
```