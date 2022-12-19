执行用时 :60 ms, 在所有 JavaScript 提交中击败了86.46%的用户

内存消耗 :33.6 MB, 在所有 JavaScript 提交中击败了99.38%的用户

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    var len = nums.length;
    if (nums[len - 1] < target) {
        return len;
    } else if (nums[0] > target) {
        return 0;
    } else {
        for (let i = 0; i < len; i++) {
            if (nums[i] == target) {
                return i;
            } else {
                if (nums[i] < target && nums[i+1] > target) {
                    return i + 1;
                }
            }
        }
    }
};
```