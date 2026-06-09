### 解题思路
循环一次，通过t标记重复的次数，注意每次splice之后需要i--，t--

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let t = 0;
    for(let i = 0; i < nums.length - 1; i++) {
        const next = nums[i + 1];
        const cur = nums[i]
        if (next === cur) {
            t++;
            if (t === 2) {
                nums.splice(i + 1, 1);
                t--;
                i--;
            }
        } else {
            t = 0;
        }
    }
    return nums.length;
};
```