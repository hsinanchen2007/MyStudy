运行速度不快，但是很容易懂的方法。

``` javascript
/**
 * @param {number[]} nums
 * @param {number} k     i-j <= k
 * @param {number} t    |nums[i] - nums[j]| <= t
 * @return {boolean}
 */
var containsNearbyAlmostDuplicate = function(nums, k, t) {
    for(var i = 0;i<nums.length-1;i++){
        for(var j = i+1;j<nums.length;j++){
            if(Math.abs(nums[i]-nums[j])<=t && Math.abs(i-j)<=k){
                return true
            }else{
                if(Math.abs(nums[i]-nums[j]) > t && Math.abs(i-j)<=k){
                    continue
                }else if(Math.abs(nums[i]-nums[j]) <= t && Math.abs(i-j) > k){
                    i = i+1;
                    j = i
                }else if(Math.abs(nums[i]-nums[j]) > t && Math.abs(i-j) > k){
                    i = i+1;
                    j = i
                }
            }
        }
    }
    return false
};
```