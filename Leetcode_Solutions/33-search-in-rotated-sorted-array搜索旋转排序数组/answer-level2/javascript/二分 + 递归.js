**思路**

算法复杂度O(log n)，我首先想到的是二分查找

1. 二分查找一定要求出中点，mid = low + high / 2

2. mid元素要么在前面的大子序列，要么在后面的小子序列；判断mid和low的大小，如果mid大于low，mid一定在大子序列；否则，一定在小子序列

3. 如果在大子序列，那么low到mid是单调递增的；如果在小子序列，那么mid到high是单调递增的

4. 递归上述过程，可以得到最终的解

----

二分 + 递归

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {

    if (nums.length == 0) return -1

    function dfs(low, high) {

        if (nums[low] == target) return low
        if (nums[high] == target) return high
        if (low == high || low == high - 1) {
            return -1
        }

        let mid = Math.floor((low + high) / 2)
        if (nums[mid] == target) return mid

        if (nums[mid] > nums[low]) { // 大子序列
            if (target > nums[low] && target < nums[mid]) {
                return dfs(low, mid)
            } else {
                return dfs(mid, high)
            }
        } else { // 小子序列
            if (target > nums[mid] && target < nums[high]) {
                return dfs(mid, high)
            } else {
                return dfs(low, mid)
            }
        }
    }

    return dfs(0, nums.length - 1)
};
```
