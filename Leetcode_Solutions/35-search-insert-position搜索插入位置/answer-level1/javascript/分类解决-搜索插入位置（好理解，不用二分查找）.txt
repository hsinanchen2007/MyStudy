第一类是target<nums[0],插入第一个位置，返回索引为0；
第二类是target>nums[nums.length-1],插入最后一个位置，返回索引为nums.length；
第三类是target处于数组之间，从nums的第一个数开始循环，找到大于target的那个数，这个数的位置就是target要插入的位置。


### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    if(nums.indexOf(target)===-1){
         if(nums[0]>target){
             return 0;
         }else if(nums[nums.length-1]<target){
             return nums.length;
         }else{
             var i=0;
             while(nums[i]<target){
               i++;
             }
             return i;
         }
    }else{
        return nums.indexOf(target);
    }
};
```