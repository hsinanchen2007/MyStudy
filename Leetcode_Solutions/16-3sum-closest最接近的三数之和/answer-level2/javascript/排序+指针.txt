### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    nums.sort((a, b) => a - b);
    var len = nums.length;
    var result = Number.MAX_SAFE_INTEGER;

    console.log(nums)

    for (var i = 0; i < len; i++) {
        var l = i + 1;
        var r = len - 1;
        var sum = 0;

        while(l < r) {
            sum = nums[i] + nums[l] + nums[r];
            var gap1 = Math.abs(target - sum);
            var gap2 = Math.abs(target - result);
            if (gap1 < gap2) {
                result = sum;
            }
            console.log(i, l, r, sum)
            if (sum === target) {
                result = sum;
                break;
            } else if (sum > target) {
                r--;
            } else {
                l++;
            }
        }
    }

    return result;
};
```