```

/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
  /* 
   F(n)代表第n天所能获取到的最大值
   如果第n天做，则第n-1天就不能做则
   F(n) = F(n-2)+nums[n]
   如果第n天不做那F(n-1)就是最大值
   所有比较这两种情况的最大值便是F(n)的值
   所以F(n)=math.Math(F(n-2)+nums[n],F(n-1))
   */
  if(nums.length===0)return  0
  if(nums.length===1)return  nums[0]
   let F = []
   F[0] = nums[0]
   F[1] = Math.max(nums[0],nums[1])
   for(let i = 2 ; i<nums.length;i++){
     F[i] = Math.max((F[i-2]+nums[i]),F[i-1])
   }
   return F[nums.length - 1]
}
```
