```
var majorityElement = function(nums) {
    let map = {}
    let resItem = ''
    nums.forEach(x=>{
        if(map[x]){
            map[x] = map[x] + 1
        }else{
            map[x] = 1
        }
    })
    for(key in map){
        if(map[key]>nums.length/2) resItem = key
    }
    return resItem
};
```
