总共的步数最小，当然要劲往一处使，数往中间靠啦，所以本题的核心在于找到中位数  ヾ(o◕∀◕)ﾉヾ

```
var minMoves2 = function(nums) {
    let result = 0
    nums = nums.sort((a, b) => {
        return a - b
    })
    let avg = nums[Math.ceil(nums.length/2) - 1]
    nums.forEach(num => {
        result += Math.abs(avg - num)
    })
    return result
};
```
