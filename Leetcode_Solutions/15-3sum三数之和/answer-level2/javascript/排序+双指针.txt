### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    var len = nums.length;
    var list = nums.sort((a, b) => (a - b));
    var arr = [];

    for (var i = 0; i < len; i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] === nums[i-1]) continue;

        var l = i + 1;
        var r = len - 1;

        while(l < r) {
            var sum = nums[l] + nums[i] + nums[r];
            if (sum === 0) {
                arr.push([nums[l], nums[i], nums[r]]);
                while((l < r) && (nums[l] === nums[l + 1])) {
                    l += 1;
                }
                while((l < r) && (nums[r] === nums[r - 1])) {
                    r -= 1;
                }
                l++;
                r--;
            } else if(sum > 0) {
                r--;
            } else {
                l++;
            }
        }
    }

    return arr;
};
```