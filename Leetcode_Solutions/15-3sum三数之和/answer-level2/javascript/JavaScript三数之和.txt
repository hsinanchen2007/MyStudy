#### 思路：
1. 数组升序排序；
2. 遍历`nums`;
3. 如果`nums[0] > 0`，则不用判断了，因为最小的数都大于0，三数之和必大于0；
4. 如果`nums[i] == nums[i - 1]`，跳过本次循环，去重；
5. 设置左右双指针，`left = i + 1，right = nums.length - 1`，计算`sum = nums[i] + nums[j] + nums[k]`；
6. 如果`sum == 0`；则保存，如果`sum < 0`；右指针往右移动，如果`sum > 0`；左指针往左移动；
7. 在`sum == 0`的情况下，左右两边可能存在连续相同的数字，需要去重；
8. 如果`nums[left + 1] == nums[left]`，则`left++`，如果`nums[right - 1] == nums[right]`，则`right--`；
#### 代码
```
var threeSum = function(nums) {
    let result = [];
    // 排序
    nums.sort((a, b) => a - b);
    for (let i = 0; i < nums.length - 2; i++) {
        if (nums[i] > 0) break; // 找不到符合条件的组合
        if (i > 0 && nums[i] === nums[i - 1]) continue; // 去重
        let j = i + 1;
        let k = nums.length - 1;
        while (j < k) {
            let sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                result.push([nums[i], nums[j], nums[k]]);
                // 从左边找到下一个和当前值不同的数
                while (j < k && nums[j] === nums[j+1]) j++;
                // 从右边找到下一个和当前值不同的数
                while (j < k && nums[k] === nums[k-1]) k--;
                j++;
                k--;
            } else if (sum < 0) {
                j++;
            } else {
                k--;
            }
        }
    }
    return result;
};
```

