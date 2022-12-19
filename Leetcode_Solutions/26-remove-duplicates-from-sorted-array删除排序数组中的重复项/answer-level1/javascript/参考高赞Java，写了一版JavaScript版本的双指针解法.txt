### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    if(nums.length < 2) {
        return nums
    }
    let i = 0, j = 1;
    while(j < nums.length) {
        if(nums[i] === nums[j]) {
            j++
        }else {
            i++
            nums[i] = nums[j]
            j++
        }
    }
    return i + 1
};
```