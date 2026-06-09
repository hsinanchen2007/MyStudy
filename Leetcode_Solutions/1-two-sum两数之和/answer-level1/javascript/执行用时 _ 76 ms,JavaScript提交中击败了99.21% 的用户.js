使用Object作为Map
```
var twoSum = function(nums, target) {
    let map = {};
    for(let i=0;i<nums.length;i++){
        let n = target-nums[i];
        let hasVal = map.hasOwnProperty(n);
        if(hasVal){
            return [map[n],i]
        }
        map[nums[i]] = i;
    }
    return []
};
```