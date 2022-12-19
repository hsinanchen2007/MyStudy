解题思路：
1. 排序，升序或降序均可
2. 循环，每三组进行相加，并判断是否等于第一项的三倍
3. 相同的话说明三个数字相同
4. 不同的话，说明肯定存在不同的数字
5. 进行异或
6. 循环完后还没有，则最后一个是


```
var singleNumber = function(nums) {
    nums = nums.sort((a, b) => a - b);
    for(var i = 2; i < nums.length; i += 3){
        if((nums[i] + nums[i - 1] + nums[i - 2]) !== nums[i]*3){
            return nums[i] ^ nums[i - 1] ^ nums[i - 2]
        }
    }
    
    return nums[nums.length - 1];
};
```
