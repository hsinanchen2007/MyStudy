```js
var findLHS = function(nums) {
    let map = new Map();
    let max = 0;
    for(let i = 0; i < nums.length; i++) {
        if(map.has(nums[i])) {
            map.set(nums[i], map.get(nums[i]) + 1)
        } else {
            map.set(nums[i], 1)
        }
    }
    for(let [key,value] of map){
        if(map.has(key+1)) {
            max = Math.max(max,map.get(key+1) + value);
        }
    }
    return max;
};
```


