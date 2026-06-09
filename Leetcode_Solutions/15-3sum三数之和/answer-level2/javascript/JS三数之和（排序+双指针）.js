先排序，三个指针，一个指针做c位，另外两个在剩下数组中从头和从后遍历
执行速率还行，但内存消耗挺大的
```
var threeSum = function(nums) {
    nums = nums.sort(function(a, b) {
        return a-b;
    });
    var k = 0;
    var result = [];
    while(k < nums.length - 2) {
        let i = k+1, j = nums.length-1;
        while(i<j) {
            var sum = nums[k] + nums[i] + nums[j];
            if(sum == 0) {
                let res = [];
                res.push(nums[k]);
                res.push(nums[i]);
                res.push(nums[j]);
                result.push(res);
            }
            if(sum <= 0){
                while(i<j && nums[i] === nums[++i]);
            }
            else {
                while(i<j && nums[j] === nums[--j]);
            }   
        }
        while(k < nums.length - 2 && nums[k] === nums[++k]);
    }
    return result;
};
```
