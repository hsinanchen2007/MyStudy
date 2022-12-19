### 解题思路
荷兰国旗问题。

用三个指针，分别是：pre 表示 0 的右边界、current 表示当前访问到的元素、post 表示 2 的左边界。
即 nums[i < pre] === 0; nums[i > post] === 2;

遍历一遍，
- 当 nums[current] === 0 时，交换 nums[current] 与 nums[pre]，pre 和 current 都右移一位。
- 当 nums[current] === 1 时，current 都右移一位。
- 当 nums[current] === 2 时，交换 nums[current] 与 nums[post]，post 左移一位。

注意：用 if 会比 switch 花费更少的时间

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
const swap = (arr, index1, index2) => {
    const temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

var sortColors = function(nums) {
    if (nums.length < 2) return;
    let pre = 0, current = 0, post = nums.length - 1;
    while (current <= post) {
        if (nums[current] === 2) {
            swap(nums, current, post);
            --post;
        } else if (nums[current] === 1) {
            ++current;
        } else {
            swap(nums, current, pre);
            ++current;
            ++pre;
        }
    }
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)