思路：两个一组
代码：
```
var decompressRLElist = function(nums) {
    let result = []
    for(let i = 0; i < nums.length / 2; i+=1) {
        result = [...result, ...new Array(nums[2*i]).fill(nums[2*i+1])]
    }
    return result
};
```