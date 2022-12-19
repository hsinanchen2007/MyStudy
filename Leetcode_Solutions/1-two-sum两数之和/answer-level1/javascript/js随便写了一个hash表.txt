/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let hash = {};
    for (let i=0; i<nums.length; i++){
        let search = target - nums[i];
        if((hash[search] != undefined) && (hash[search] != i)){
            return [hash[search], i];
        }
        hash[nums[i]] = i;
    }
};