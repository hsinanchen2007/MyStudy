1. indexOf方法
indexOf可返回某个指定的字符串值在字符串中首次出现的位置


```
var containsDuplicate = function(nums) {
    var len = nums.length;
    
    for(var i = 0; i < len; i++) {
        // 若后一次出现该元素，但根据indexOf的性质只会返回该元素第一次出现的下标
        if(nums.indexOf(nums[i]) != i) {
            return true;
        }
            
    }
    return false;
};
```
2. 排序法
sort()可对原数组进行排序，不返还新数组。
```
var containsDuplicate = function(nums) {
    nums.sort();
    var len = nums.length;
    for(var i = 0; i < len; i++) {
        if(nums[i] == nums[i+1]) 
            return true;
    }
    return false;
};
```
3. indexOf和lastindexOf
lastIndexOf 是从右向左查某个指定的字符串在字符串中最后一次出现的位置（也就是从后往前查）
```
var containsDuplicate = function(nums) {
    var len = nums.length;
    for(var i = 0; i < len; i++) {
        // 若数值第一次出现的位置不等于最后一次出现的位置，说明该数组存在重复元素
        if(nums.indexOf(nums[i]) != nums.lastIndexOf(nums[i])) 
            return true;
    }
    return false;
};
```
4. set去重
set中不能重复元素
```
var containsDuplicate = function(nums) {
    var x = new Set(nums);

    if(nums.length == x.size)
        return false;
    
    return true;
};
```
