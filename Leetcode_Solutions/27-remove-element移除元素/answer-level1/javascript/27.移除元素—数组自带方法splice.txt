### 解题思路
1、判断数组中的数是否等于val，等于则移除
2、使用数组自带方法splice（start,num）(开始位置，个数)；

注意：移除后i--;

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    for(var i =0;i<nums.length;i++){
        if(nums[i] === val){
            nums.splice(i,1);
            i--;
        }
    }
    return nums.length;
};
```