## 超过 98% 以上：js
```
var threeSum = function(nums) {
    nums = nums.sort((a, b) => a - b)
    let res = []
    for(let i = 0;i < nums.length-2;i++) {
        if(i >= 1 && nums[i] === nums[i-1]) {
            continue
        }
        let j = i + 1
        let k = nums.length - 1
        while(j < k) {
            let sum = nums[i] + nums[j] + nums[k]
            if(sum === 0) {
                res.push([nums[i], nums[j], nums[k]])
                j++
                while(nums[j-1] === nums[j]) {
                    j++
                }
            } else if(sum < 0) {
                j++
            } else {
                k--
            }
        }
    }

    return res
}

内部有小循环来过滤重复～