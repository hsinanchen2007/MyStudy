根据题意使用标记法遍历一次即可出结果
```javascript []
var findRepeatNumber = function(nums) {
    for(let i = 0; i < nums.length; i++){
        if(nums[Math.abs(nums[i])] < 0) return Math.abs(nums[i])
        nums[nums[i]] = -nums[nums[i]]
    }
    return 0;
};
```
