/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    var arr=[-1,-1]
    
    for(var i=0;i<nums.length;i++){
         if(nums[i]==target){
            arr[0]=i
            for(var j=i;j<nums.length;j++){
                if(nums[j]==target){
                    arr[1]=j
                   
                }                
            }
          break 
         }   
    }
    return arr
    
};