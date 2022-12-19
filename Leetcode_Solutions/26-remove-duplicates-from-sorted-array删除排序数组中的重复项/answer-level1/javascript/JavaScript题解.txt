### 解题思路
双指针，写完发现用for其实更舒服

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    var index=1;
    var len=nums.length;
    var i=0;
    while (index<nums.length){
        if (nums[i]===nums[index]){
            index++
            len--
        }
        else {
            nums[i+1]=nums[index]
            i++
            index++
        }
    }
    return len;
};
```