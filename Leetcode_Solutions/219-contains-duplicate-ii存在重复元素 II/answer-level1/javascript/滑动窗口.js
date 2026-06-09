```
var containsNearbyDuplicate = function(nums, k) {
    for(var i=0;i<nums.length;i++) {
        for(var j=Math.max(i-k,0);j<i;j++){
            if(nums[i]==nums[j] ){
                    return true;
                }
            }
        }
    return false;
};
```
