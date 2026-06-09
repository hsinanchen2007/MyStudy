### 解题思路
此处撰写解题思路
1、利用对象键值对以及undefined特性
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    let result = ''
    nums.sort(function(before, after) {
        return before- after
    })
    for(let i=0; i < nums.length; i++) {
        result = '无重复值'
        if(i + 1 < nums.length && nums[i] === nums[i + 1]) {
            result = nums[i]
            break
        }
    }
    return result
};

```