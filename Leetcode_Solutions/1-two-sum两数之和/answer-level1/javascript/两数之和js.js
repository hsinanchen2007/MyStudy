遍历次数小的话hashMap比暴力法用时多啊。。
Map:
```JavaScript
var twoSum = function(nums, target) {
    if (Object.prototype.toString.call(nums) !== '[object Array]'|| typeof target !== 'number') {
        return
    }
    const arrMap = new Map()
    for(let i =0; i < nums.length; i++) {
        arrMap.set(nums[i], i)
        
    }
    for(let i =0; i < nums.length; i++) {
        const result = target - nums[i];
        if (arrMap.has(result) && arrMap.get(result) !== i) {
            return [arrMap.get(result), i];
        }
        
    }
};
twoSum([2,7,11,15], 9);