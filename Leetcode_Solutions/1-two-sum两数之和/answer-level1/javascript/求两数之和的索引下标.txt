### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
   for(let i =0;i<nums.length;i++){
       let param = target-nums[i]
       if(nums.includes(param)){
           let index = nums.findIndex((ele,ind)=>{
                   return ele===param
           })
           if(index === i) {
               continue
           } else {

           return [i,index]
           }
       }
   }
};
```
目标值已确定，遍历数组，判断数组中是否有目标值减去当前项的值，有的话就查找对应的索引，又因为不能重复本身，所以查找出来的索引和当前循环次数不能相等，跳过该步骤继续遍历，直到找出符合条件的结果