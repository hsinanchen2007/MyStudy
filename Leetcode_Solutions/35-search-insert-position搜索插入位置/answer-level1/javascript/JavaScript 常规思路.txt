### 解题思路
    先循环，再比较
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== target) {
            if(target > nums[nums.length - 1]){
                return nums.length
            }else{
               if (target < nums[i]) {
                    return i
                } 
            }
        }else{
            return nums.indexOf(target)
            break;
        }
    }
};
```