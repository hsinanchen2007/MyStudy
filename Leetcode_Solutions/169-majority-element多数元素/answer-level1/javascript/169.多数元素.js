方法一、暴力法
```
var majorityElement = function(nums) {
    for(var i=0;i<nums.length;i++){
        var count=0;
        for(var j=0;j<nums.length;j++){    
            if(nums[i]===nums[j]){
                count++;
            }
        }
        if(count>(nums.length/2)){
            return nums[i];
        }
    }
    return -1;
};
```
方法二、排序
```
var majorityElement = function(nums) {
    nums.sort();
    return nums[Math.floor(nums.length/2)];
};
```
