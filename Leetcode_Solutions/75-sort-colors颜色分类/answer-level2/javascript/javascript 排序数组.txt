### 解法一
计数排序

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    const len = nums.length
    let i = 0, j = 0, k = 0
    for (let index = 0; index < len; index++) {
        const num = nums[index]
        if (num === 0) {
            i ++
        } else if (num === 1) {
            j ++
        } else {
            k ++
        }
    }
     for (let index = 0; index < len; index++) {
        if (index < i) {
            nums[index] = 0
        } else if (index < i + j) {
            nums[index] = 1
        } else {
            nums[index] = 2
        }
    }
};
```

### 解法二
快排序思想，遍历一遍，如果是0放在数组前面，是2放在数组末尾
```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    const len = nums.length
    for (let i = 0; i < len; i++) {
        if (nums[i] === 0) {
            nums.unshift(nums.splice(i, 1))
        } else if (nums[i] === 2) {
            nums.push(nums.splice(i, 1))
            // 注意放在末尾需要维护索引变化
            i--
        }
    }
}
```
```