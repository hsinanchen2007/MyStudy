```
/**
 * @param {number[]} nums
 * @return {number}
 */
var triangleNumber = function(nums) {
    let res = 0
    let length = nums.length
    // 对数组进行排序
    nums.sort((a, b) => {
        if (a < b) return -1
        if (a > b) return 1
        if (a === b) return 0
    })
    for (let i = length - 1; i >= 2; --i) {
        let left = 0
        let right = i - 1
        while (left < right) {
            // 左右两边的两个指针对应的数大于当前所在的值，则left之前的（包括left）都是符合条件的
            if (nums[left] + nums[right] > nums[i]) {
                res += right - left
                --right
            } else {
                ++left
            }
        }
    }
    return res
}
```
![image.png](https://pic.leetcode-cn.com/bc36e382240970a9918af5f5fc9fbbbeb752d78e9ca9c8f01a6789f7788e370c-image.png)
