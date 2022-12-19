```js
var rob = function(nums) {
    let max =[0,nums[0]]
    let n = nums.length
    for(let i=1; i<n; i++){
        max[i+1] = Math.max(max[i], max[i-1]+nums[i] )
    }
    return max[n]
};
```
