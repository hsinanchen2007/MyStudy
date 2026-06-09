首先想到就是要知道两个数，首先得知道第一个数是多少，所以用到了循环
**nums[i]**是第一个数
**target - nums[i]**是第二个数
但是因为有很多种可能，所以用双层循环
第一层循环是用**target - 第一个数**知道第二个数
第二层循环是用上一步得到的数对数组的每一项进行的对比
如果有相同的，证明nums[i]和nums[j]就是我们想要的两个数
i和j就是我们要的下标
```
var twoSum = function(nums, target) {
    for(let i = 0; i < nums.length; i++) {
        for(let j = 0; j < nums.length; j++) {
            if(target - nums[i] == nums[j]) {
                return [i,j];
            }
        }
    }
};
```
