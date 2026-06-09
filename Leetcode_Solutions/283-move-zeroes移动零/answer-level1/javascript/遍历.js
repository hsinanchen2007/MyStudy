### 解题思路
遍历数组，当数组元素不等于0，而且当前下标和定义的num不相等，说明在之前出现过元素等于0 
进行替换，nums[num]等于当前下标内的元素，而当前下标元素则是等于0
以此类推，返回最后数组

### 代码

```javascript
var moveZeroes = function(nums) {
  var num = 0
    for(var i = 0; i < nums.length; i++) {
        if(nums[i] != 0) {
            if( i != num) {
            nums[num] = nums[i]
            nums[i] = 0
            }
        num++
        }
    }
    return nums
};
```