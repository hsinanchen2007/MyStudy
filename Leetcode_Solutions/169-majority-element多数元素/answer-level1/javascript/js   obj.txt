```javascript []
var majorityElement = function(nums) {
    let obj = {}
    let max = nums.length/2
    for (let i of nums) {
        obj[i] = obj[i] ? obj[i] + 1 : 1
        if (obj[i] > max) {
            return i
        }
    }
};
```
