### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
    if (!nums || nums.length < 4) return [];
    nums = nums.sort((a, b) => a - b);
    let left, right, res = [];
    for (let i = 0; i < nums.length - 3; i++) {
        if (i > 0 &&nums[i] === nums[i-1]) {
            continue;
        }
        for (let j = i + 1; j < nums.length - 2; j++) {
            if (j > i + 1 && nums[j] === nums[j-1]) {
                continue;
            }
            left = j + 1;
            right = nums.length -1;
            while (left < right) {
                if (nums[i] + nums[j] + nums[left] + nums[right] > target) {
                    right--;
                } else if(nums[i] + nums[j] + nums[left] + nums[right]< target) {
                    left++;
                } else {
                    res.push([nums[i], nums[j], nums[left], nums[right]]);
                    while (left < right -1 && nums[left] === nums[left+1]) {
                        left++;
                    }
                    while (left < right -1 && nums[right] === nums[right-1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
    }
    return res;
};
```