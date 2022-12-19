```
var majorityElement = function(nums) {
    const tar = nums.length / 2;
    let i = tar * 2;
    const resord = {};
    while(i--) {
        resord[nums[i]] = resord[nums[i]] ? resord[nums[i]] + 1 : 1;
        if(resord[nums[i]] > tar) return nums[i];
    }
    return 0;
};
```
