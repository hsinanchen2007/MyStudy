### 解题思路
1. 理解题意: 典型的排序数组去重
2. 去重就意味着元素对比, 首先考虑到的是双指针法
3. 声明一个快指针, 用来找不同; 再声明一个慢指针, 用来做元素的替换
4. 最后直接返回慢指针的长度

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    if(nums.length < 2) nums.length
    let s = 0
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] !== nums[s]) {
            s++
            nums[s] = nums[i]
        }
    }
    return s + 1
};
```