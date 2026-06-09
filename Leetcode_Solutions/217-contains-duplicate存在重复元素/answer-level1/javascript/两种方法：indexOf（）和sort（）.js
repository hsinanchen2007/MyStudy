方法一、indexOf()返回第一次出现该字符的索引
```
var containsDuplicate = function(nums) {
    for(var i=0;i<nums.length;i++) {
        if(nums.indexOf(nums[i])!=i){
            return true;
        }
    }
    return false;
};
```
方法二、sort()对数组进行排序使用该函数在原来的数组进行操作
```
var containsDuplicate = function(nums) {
    nums.sort();
    for(var i=0;i<nums.length;i++) {
        if(nums[i]==nums[i+1]){
            return true;
        }
    }
    return false
};
```
