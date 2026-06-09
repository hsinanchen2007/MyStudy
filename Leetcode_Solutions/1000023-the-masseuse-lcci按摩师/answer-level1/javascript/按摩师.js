```
var massage = function(nums) {
    let a = 0, b = 0
    for (let i = 0; i < nums.length; i++) {
    let c = Math.max(b, a + nums[i])
        a = b
        b = c
    }
    return b
}

```
