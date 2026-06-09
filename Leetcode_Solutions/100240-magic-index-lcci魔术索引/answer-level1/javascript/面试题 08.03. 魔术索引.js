### 解题思路

题目只告诉我们，这是个 ``有序数组``，意味着可能出现以下数据：

- ``[0, 0, 2]``
- ``[1, 1, 1]``

所以当我们找到一个数值时，不能盲目二分，因为：

- 找到 ``nums[mid] === mid``，可能左边还有更小的魔术索引
- 无论 ``nums[mid] > mid`` 还是 ``nums[mid] < mid``，不能断言就能往左边或者右边二分

正确的策略：

- 当 ``nums[mid] === mid`` 时，往左边 ``递归`` 找到更小的魔术索引
- 其他情况，往 ``mid`` 的左边和右边分别进行 ``递归``，优先选择左边找到的魔术索引


### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMagicIndex = function(nums) {
    const helper = (lo, hi) => {
        if (lo > hi) {
            return -1
        }
        let mid = Math.floor((lo + hi) >> 1)
        if (nums[mid] === mid) {
            let res = helper(lo, mid - 1)
            return ~res ? res : mid
        }
        let left = helper(lo, mid - 1)
        let right = helper(mid + 1, hi)
        return ~left ? left : right
    }
    return helper(0, nums.length - 1)
};
```