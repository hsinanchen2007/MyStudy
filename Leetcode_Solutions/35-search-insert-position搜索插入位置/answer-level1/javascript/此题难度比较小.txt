### 解题思路
此处撰写解题思路
遍历数组所有数字是否有大于或者等于目标值，如果有，就替代此数字的索引，若果没有就默认为数组的长度；
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    var pointList=[];
    var temp=-1;
    for(var i in nums){
        if(nums[i]>=target){
            temp=i;
            break;
        }else{
            if(i==nums.length-1){
                temp=nums.length;
            }
        }
    }
    return temp;
};
```