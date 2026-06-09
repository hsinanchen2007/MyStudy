```
var containsDuplicate = function(nums) {
    const set = new Set();
    for(let el of nums){
        if(set.has(el)){
            return true;
        }
        set.add(el)
    }
    return false
};
```
