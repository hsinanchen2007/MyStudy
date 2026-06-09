# set排重数组对比
首先想到的是用set排重，然后转成数组对比大小~
```
var containsDuplicate = function(nums) {
    return Array.from(new Set(nums)).length != nums.length;
};
```
# set size
然后突然想到set的size方法，直接对比不好么，O(n)的空间复杂度，O(1)的时间复杂度，假设js中数组转set是O(1)~
```
var containsDuplicate = function(nums) {
    return new Set(nums).size != nums.length;
};
```
# hash表
其实这块不管是用set也好还是map也好还是一个普通对象，都是通过额外数据结构去构建一个数据hash表，在遍历过程中查看是否已经存在~
```
var containsDuplicate = function(nums) {
    let set = new Set();
    for(let i = 0,len = nums.length;i<len;i++){
        if(set.has(nums[i])){
            return true;
        }
        set.add(nums[i]);
    }
    return false;
};
```
# 排序
排序之后对比相邻元素，看是否重复，空间复杂度是O(1),时间复杂度略高~
```
var containsDuplicate = function(nums) {
    nums.sort((a,b)=>a-b);
    for(let i = 1,len = nums.length;i<len;i++){
        if(nums[i-1] == nums[i]){
            return true;
        }
    }
    return false;
};
```
