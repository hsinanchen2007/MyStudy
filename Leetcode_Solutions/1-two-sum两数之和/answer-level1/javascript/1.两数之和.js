### 解题思路
从第一个数开始做遍历,每遍历一个数,尝试与后面的每个数相加,看结果是否等于target,是就返回i,j构成的数组

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    for(var i=0;i<nums.length;i++){
        for(var j=i+1;j<nums.length;j++){
          if(nums[i]+nums[j]==target){
              var arr=[i,j];
              return arr;
          }
        }
    }

};
```