保证迭代的 **index** 是下一位就可以保证 **tmp** 数组内的元素不会重复，所以记录 **tmp** 变化历程就是 **nums** 全部子集

```
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    let res = []
    const backtrack = (nums, index, tmp) => {
        res.push(tmp.slice())
        for (let i = index; i < nums.length; i++) {
            tmp.push(nums[i])
            backtrack(nums, i + 1, tmp)
            tmp.pop()
        }
    }
    backtrack(nums, 0, [])
    return res
};
```