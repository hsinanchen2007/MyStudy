/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
    if(nums.length<4){
        return []
    }else {
        nums.sort((a,b)=>{
            return a-b
        })
        let result = []
        let map = new Map();
        for(let i = 0;i<nums.length;i++){
            for(let j = i+1;j<nums.length;j++){
                for(let k = j+1;k<nums.length;k++){
                    for(let l = k+1;l<nums.length;l++){
                        if(target == (nums[i]+nums[j]+nums[k]+nums[l])){
                            if(!map.has(nums[i]+"_"+nums[j]+"_"+nums[k]+"_"+nums[l])){
                                result.push([nums[i],nums[j],nums[k],nums[l]])
                                map.set(nums[i]+"_"+nums[j]+"_"+nums[k]+"_"+nums[l],1)
                            }
                            
                        }
                    }
                }
            }
        }
        return result
    }
};