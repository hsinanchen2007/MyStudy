### 解题思路
回溯问题

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    const res = []
    const len = nums.length
    if (len) {
        //在1，2, ... , n中取k个数的组合，放在数组c中
        function _combine (nums, k, c) {
            if (k === 0) {
                res.push(c)
                return
            }
            const len = nums.length
            for (let i = 0; i <len; i++) {
                const c1 = [...c]
                c1.push(nums[i])
                const arr = nums.slice(i + 1)
                _combine(arr, k - 1, c1)
            }
        }
        for (let i = 0; i <= len; i++) {
            _combine(nums, i, [])
        }
    }
    return res
};
```