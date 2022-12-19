### 每次选取前n-2个中最大的时间和

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    var len = nums.length;
    if(len < 2 ) return len == 0 ? 0 : nums[0];
    if(len <= 2) return Math.max(nums[0], nums[1]);
    var times = [];
    times[0] = nums[0];
    times[1] = nums[1];
    for(var i = 2; i < len; i++){
        times[i] = nums[i];
        for(var j = i-2; j >= 0; j--)
            times[i] = Math.max(times[i], times[j]+nums[i]);
    }
    return Math.max(times[len-1], times[len-2]);
};
```