```
var isStraight = function(nums) {
    let arr = nums.sort((a, b) => a - b)
    let zeroN = nums.lastIndexOf(0) + 1
    for(let i = zeroN + 1; i < nums.length; i++){
        if(nums[i] - nums[i-1] != 1){
            if(zeroN > 0){
                zeroN--
                nums[i-1] += 1
                i--
                continue;
            }else{
                return false;
            }
        }
    }
    return true;
};
```
