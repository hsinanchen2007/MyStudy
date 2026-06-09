### 解题思路
此处撰写解题思路

### 代码

```javascript

// 用map来记录，若是map中已经存在该值，那么则返回
var containsDuplicate = function(nums) {
    let map = new Map();
    for(let i=0; i<nums.length; i++){
        if(map.has(nums[i])) return true;
        map.set(nums[i],i)
    }
    return false;
};

// 用set的不会重复添加的特性，若是set的大小与数组的长度不一致 说明有重复的值
var containsDuplicate = function(nums) {
    if(nums.length<2) return false;
    let set = new Set(nums);
    return set.size !== nums.length;
};
```