### 解题思路
回溯

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
 var permute = function(nums) {
     // 保存最终的结果
    const res = []
    // 用来记录每一步排列中，数字是否已经使用
    const used = new Array(nums.length).fill(false)
    function _permute (nums, index, p) {
       const len = nums.length
       if (len === index) {
           res.push(p)
           return 
       }
       for (let i = 0; i < len; i++) {
           if (!used[i]) {
              p.push(nums[i])
              used[i] = true
              const p1 = [...p]
              _permute(nums, index + 1, p1)
               // 这一轮使用后，回溯，下一轮还可以使用
              p.pop()
              used[i] = false
           }
       }
       return
    }
    _permute(nums, 0, [])
    return res
};
```