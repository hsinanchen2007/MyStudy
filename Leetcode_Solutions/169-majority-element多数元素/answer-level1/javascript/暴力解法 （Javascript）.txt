/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let len = (nums.length)/2
    let sortnums = nums.sort()
    let count = 0
    let num = sortnums[0]
    for(let i = 0;i < sortnums.length; i++){
        if(sortnums[i] == num){
            count++
        }else{
            num = sortnums[i]
            count = 0            
            count++
        }
        
        if(count > sortnums.length/2){
             break;
        }
    }
   return num
};