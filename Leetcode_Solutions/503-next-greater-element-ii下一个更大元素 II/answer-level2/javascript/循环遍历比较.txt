遍历原数组，再根据拼接一次原数组进行循环判断
```js
var nextGreaterElements = function(nums) {
    var res = [];
    var _nums = nums.concat(nums);
    for(var i=0;i<nums.length;i++){
        var flag = true;
        for(var j=i+1;j<_nums.length;j++){
            if(nums[i]<_nums[j]){
                res.push(_nums[j]);
                flag = false;
                break;
            }
        }
        if(flag) res.push(-1);
    }
    return res;
};
```