### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    let result = []
    let map = {} // -1: 0,1
    nums.sort((a, b) => a - b); // 升序
    if (nums.length < 3) return []
    for (let i = 0, len = nums.length; i < len; i++) {
        if (nums[i] > 0) break; // 排序后大于0，说明后面都大于0，不可能想加为0
        if (nums[i] === nums[i+1]) continue // 重复情况，去除 ，不考虑
        let left = i+1; // 右边第一位
        let right = nums.length - 1 // 最末位
        while (left < right) {
            let sum = nums[i] + nums[left] + nums[right] 
            if (sum=== 0) { // 和为0
                result.push([nums[i], nums[left], nums[right]]);
                while(nums[left] === nums[left + 1]) { // 剔除重复情况
                    left++;
                }
                while(nums[right] === nums[right - 1]) { // 剔除重复情况
                    right--
                }
                left++ // 继续遍历
                right-- // 继续遍历
            } else if (sum > 0) {
                right--
            } else {
                left++
            }
        }
    }
    return result
};
```