```javascript []
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = (nums)=> {
   const sort = (nums,left =0 ,right = nums.length-1) => {
       if(left>=right){
           return
       }
       let i = left
       let j = right
       let baseval = nums[j]
       while(i<j){
           while(i<j&&nums[i]<=baseval){
               i++
           }
           nums[j] = nums[i]
           while(i<j&&nums[j]>=baseval){
               j--
           }
           nums[i] = nums[j]
       }
       nums[j] = baseval
       sort(nums,left,j-1)
       sort(nums,j+1,right)
   }
   const newArr = nums.concat()
   sort(newArr)
   return newArr
};
```
![image.png](https://pic.leetcode-cn.com/9eec609f16f2f37da1b4c12cf9ac0f48db10ad32154ef07f957f34558f35a449-image.png)
