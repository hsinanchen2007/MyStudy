居然说我空间复杂度超过了百分百的js提交。。。感觉不真实
```
var majorityElement = function(nums) {
    if(nums.length==1) return nums[0];
    let map=new Map();
    for(let i=0;i<nums.length;i++){
        if(map.has(nums[i])){
            map.set(nums[i],map.get(nums[i])+1);
            if(map.get(nums[i])>nums.length/2) return nums[i];
        }
        else map.set(nums[i],1);
    }
    return -1;
};
```
