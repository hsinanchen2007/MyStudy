var removeDuplicates = function(nums) {
    nums.sort((a,b) => a < b ? -1 : (a > b ? 1: 0));
 
 for(let i = 0; i< nums.length - 1; i++) {
    for(let j = i+1; j<nums.length; j++) {
        if(nums[i] === nums[j]) {
            nums.splice(j--, 1);
        }
    }
 };
     return nums.length;
 };