### 解题思路
回溯算法

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
    const res = []
    if (n >= k && n > 0 && k > 0) {
        //在1，2, ... , n中取k个数的组合，放在数组c中
        function _combine (nums, k, c) {
            if (k === 0) {
                res.push(c)
                return
            }

            for (let i = 0; i < nums.length; i++) {
                const c1 = [...c]
                c1.push(nums[i])
                const arr = nums.slice(i + 1)
                _combine(arr, k - 1, c1)
            }
        }
        const nums = []
        for (let i = 1; i <= n; i++) {
            nums.push(i)
        }
        _combine(nums, k, [])
    }
    return res
};
```