```
var maxProduct = function(nums) {
        let max = Number.MIN_SAFE_INTEGER, imax = 1, imin = 1;
        for(let i=0,len=nums.length; i<len; i++){
            if(nums[i] < 0){ 
              let tmp = imax;
              imax = imin;
              imin = tmp;
            }
            imax = Math.max(imax*nums[i], nums[i]);
            imin = Math.min(imin*nums[i], nums[i]);
            
            max = Math.max(max, imax);
        }
        return max;
    }
```
