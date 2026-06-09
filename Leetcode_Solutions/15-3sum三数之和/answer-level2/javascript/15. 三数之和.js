### 解题思路

由于数组中会有重复的数字，所以一开始可以先 ``排序``，然后利用三个指针：
第一个固定头部，剩下两个指针就跟常规的双指针写法一样，其中：

- 若 $sum = 0$，那么将结果 ``push`` 到数组中，同时剔除重复元素；
- 若 $sum < 0$，那么将 ``left`` 指针右移；
- 若 $sum > 0$，那么将 ``right`` 指针左移。


### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    let res = []
    let N = nums.length
    nums.sort((a, b) => a - b)
    for (let i = 0; i < N; i++) {
        // 由于 nums[i] <= nums[left] <= nums[right]
        // 如果 nums[i] > 0，说明可以直接结束循环了
        if (nums[i] > 0) {
            break
        }
        // 跳过重复的元素
        if (nums[i] === nums[i - 1]) {
            continue
        }
        let left = i + 1
        let right = N - 1
        //  这里的逻辑可以参考上面所说的，不再赘述
        while (left < right) {
            let sum = nums[i] + nums[left] + nums[right]
            if (sum === 0) {
                res.push([nums[i], nums[left], nums[right]])
                while (left < right && nums[left] === nums[left + 1]) {
                    left++
                }
                while (left < right && nums[right] === nums[right - 1]) {
                    right--
                }
                left++
                right--
            } else if (sum < 0) {
                left++
            } else {
                right--
            }
        }
    }
    return res
};
```
- 时间复杂度：$O(n^2)$
- 空间复杂度：$O(1)$