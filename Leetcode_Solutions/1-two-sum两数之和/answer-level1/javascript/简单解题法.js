
有点取巧。。不过我只想追求下速度。68ms超越88
```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    if(nums==null ||nums.length==0 || target == null){
        return;
    }
    for(var i=0;i<nums.length;i++){
        if(nums[i]+nums[(i+1)]==target){
            return[i,(i+1)]
        }
    }
    var curpos = 0;
    while(curpos<=nums.length){
        if(curpos == nums.length){
            return;
        }
        for(var i=(curpos+1);i<nums.length;i++){
            if(nums[curpos]+nums[i] == target){
                return [curpos,i]
            }
        }
        curpos++
    }
};
```
