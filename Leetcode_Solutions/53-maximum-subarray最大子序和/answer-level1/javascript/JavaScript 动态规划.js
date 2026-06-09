```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    //动态规划
    let curmaxsum = nums[0],
         maxsum = nums[0];
    for(let i=1;i<nums.length;i++){
       curmaxsum = Math.max(curmaxsum+nums[i],nums[i]);
       maxsum = Math.max(curmaxsum,maxsum);
    }
    return maxsum;
};
```