直接贴代码了
冒泡 判断是否相等
var containsNearbyDuplicate = function(nums, k) {
   for(var i=0;i<nums.length;i++)    
       {
           for(var a=i+1;a<nums.length;a++)
               {
                   if(nums[i]==nums[a])
                       {
                           if(a-i<=k) //判断index差是否小于k
                               {
                                   return true;
                               }
                       }
               }
       }
    return false
    
};