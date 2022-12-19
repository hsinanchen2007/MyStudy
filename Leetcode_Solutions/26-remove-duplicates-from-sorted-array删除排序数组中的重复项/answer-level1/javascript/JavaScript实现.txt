JavaScript实现： 
一开始用的直接循环，比较前后两个元素，相同的话就去掉一个，然后返回数组长度，时间复杂度是O(n)，但是运行时间只打败了28%的人。 
后来根据题解做了双指针，运行时间打败了99%的人

双指针避免了删除操作，提高了时间效率


```
var removeDuplicates = function(nums) {
    let i = 0;
    for(var j = 0 ; j < nums.length ; j++ ) {
        if(nums[i] !== nums[j]){
            i++
            nums[i] = nums[j]
        }
    }
    return i+1
};
```
