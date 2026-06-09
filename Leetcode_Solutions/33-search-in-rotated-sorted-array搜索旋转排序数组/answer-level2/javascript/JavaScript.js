```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    // Guard
    if (nums.length === 0) return -1
    if (nums.length === 1) return nums[0] === target ? 0 : -1
    // Processing
    let li = 0, ri = nums.length-1
    while(li !== ri) {
        // 中间位
        const mi = Math.floor((ri-li)/2) + li
        if (nums[mi] === target) {
            return mi
        }
        // 剩余两位的情况
        if (li === mi) {
            if (nums[ri] === target) {
                return ri
            } else {
                return -1
            }
        }
        // 左侧索引
        const ll = li
        const lr = mi - 1
        // 右侧索引
        const rl = mi  +1
        const rr = ri
        // 判断左侧是否仅剩一位
        if (ll === lr) {
            if (nums[ll] === target) {
                // 匹配, 直接返回
                return ll
            } else {
                // 否则取右侧区间
                li = rl
                ri = rr
                continue
            }
        }
        // 判断右侧是否仅剩一位
        if (rl === rr) {
            if (nums[rl] === target) {
                // 匹配, 直接返回
                return rl
            } else {
                // 否则直接取左侧区间
                li = ll
                ri = lr
                continue
            }
        }
        // 左侧是否包含旋转区域
        if (nums[ll] > nums[lr]) {
            // 包含
            // 是否在左侧区间内
            if (nums[ll] <= target || nums[lr] >= target) {
                // 在
                li = ll
                ri = lr
            } else {
                // 不在
                li = rl
                ri = rr
            }
        } else {
            // 不包含
            // 是否在左侧区间内
            if (nums[ll] <= target && target <= nums[lr]) {
                // 在
                li = ll
                ri = lr
            } else {
                // 不在
                li = rl
                ri = rr
            }
        }
    }
    return nums[li] === target ? li : -1
};
```