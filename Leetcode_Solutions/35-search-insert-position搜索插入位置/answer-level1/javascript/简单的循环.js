### 解题思路
题既然给定的是有序不重复数据
循环 当循环值大于等于目标值的时候 即输出
特殊情况
数组中的值均小于目标值 即返回插入后的末尾下标即可

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    for(let i =0;i<nums.length;i++){
        if(nums[i] >= target){
            return i
         }
         if(i == nums.length-1){
             return i+1
         }
    }
    return 0
};
```