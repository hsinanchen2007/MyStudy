#### 解法：双指针
+ [解法同 - 26. 删除排序数组中的重复项 - 解法二](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/26-shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-xian-6/)
+ 唯一区别是从第三、一个元素起开始比对
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let count = 0
    let n = nums.length
    if(n < 3) return n
    let j = 1
    for(let i = 2;i < n;i++) {
        if(nums[i] != nums[j-1]) {
            j++
            nums[j] = nums[i]
        }
    }
    return j + 1
};
```