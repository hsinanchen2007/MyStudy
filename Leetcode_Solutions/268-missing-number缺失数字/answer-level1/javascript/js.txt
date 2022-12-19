
1.判断首位是否是0
2.判断末尾是否是数组长度的值
3.如果满足以上条件 那么值肯定在范围内缺失的值





```
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
   
   nums.sort((a,b)=> {return a-b})
   

    if(nums[0]!==0) {
     return 0
    
    } else {
      if(nums[nums.length-1]!==nums.length){
        return nums.length
      } else {
        for(let i=0;i<nums.length;i++){
          if(i!==nums[i]) {
              return i
              break
          }
       }
      }

    }
   
};
```
