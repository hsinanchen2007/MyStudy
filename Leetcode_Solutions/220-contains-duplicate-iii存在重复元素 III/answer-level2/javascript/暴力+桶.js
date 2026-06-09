方法一、暴力
```
var containsNearbyAlmostDuplicate = function(nums, k, t) {
    for(var i=0;i<nums.length;i++){
        for(var j=0;j<nums.length;j++){
            if(i!=j){
                if(((nums[i]-nums[j])<=t) && ((nums[j]-nums[i])<=t)){
                    if((i-j)<=k &&(j-i)<=k){
                        return true;
                    }
                }
            }
        }
    }
    return false;
};
```
方法二、桶
