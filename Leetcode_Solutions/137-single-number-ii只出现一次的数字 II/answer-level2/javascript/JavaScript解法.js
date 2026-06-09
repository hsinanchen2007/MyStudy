```
var singleNumber = function(nums) {
    nums.sort(function(a, b){return a - b});
    let i=0;
    let res=0;
    for(let j=0;j<nums.length;j++){
        if(i<2||nums[j]!=nums[i-2]){
            nums[i]=nums[j];
            i++
        }
    }
    for(let l=0;l<=i-1;l++){
        res^=nums[l]
    }
    return res
};
```
这个和
**《只出现一次的数字一》**
不同的在与重复的数字出现了三次，单纯的用异或是得不到结果的，既然如此，那就把数组变成只出现两次的不就可以实现了吗，刚好之前刷到除去重复的
**《删除排序数组中的重复项》**
这道题，刚好就是要求把数组变成只重复两次，但是这道题的前提是数组是按升序排序的，没问题，我们把数组先排序再处理不就好了吗，虽然时间复杂度和空间都不好看，但是这是第一次自己独立做出的中等难度的题目，而且结合了以前刷到过的题，纪念一下
