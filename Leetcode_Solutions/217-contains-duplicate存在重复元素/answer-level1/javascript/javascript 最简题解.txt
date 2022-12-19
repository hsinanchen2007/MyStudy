```javascript []
var containsDuplicate = function(nums) {
    return nums.reduce(([result, cacheObj], item) => {
        if (cacheObj[item]) result = true
        else cacheObj[item] = true

        return [result, cacheObj]
    }, [false, {}])[0]
}
```
