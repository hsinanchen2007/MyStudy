## 第一版
> 80ms,34.7MB。时间复杂度O(n),空间复杂度O(1)
```javascript []
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var increasingTriplet = function(nums) {
  let first = nums[0];
  let second = null;
  for (let i = 1; i < nums.length; i++) {
    if (second === null) {
      if (nums[i] > first) second = nums[i];
      else first = nums[i];
    } else {
      if (nums[i] > second) return true;
      if (nums[i] > first) second = nums[i];
      else first = nums[i];
    }
  }
  return false;
};
```
### 思路：用一个三元数组`incArr = [null, null, null]`保存递增子序列。遍历一次原始数组，每次实时更新数组`incArr`的某一项。
示例：原始数组为`nums = [4, 2, 6, 5, -3, 7]`
1. 当前索引`i = 0`，`incArr[0] = nums[0], incArr = [4, null, null]`。初始化子序列最小值。
2. 当前索引`i = 1`，`∵ nums[1] < incArr[0]; ∴ incArr[0] = nums[1], incArr = [2, null, null]`。更新子序列最小值。
3. 当前索引`i = 2`，`∵ nums[2] > incArr[0]; ∴ incArr[1] = nums[2], incArr = [2, 6, null];`。在第二项还未有值的时候，如果遍历中当前元素大于子序列最小值，此时更新子序列第二大的值。
4. 当前索引`i = 3`，`∵ nums[3] < incArr[1] && nums[3] > incArr[0]; ∴ incArr[1] = nums[3], incArr = [2, 5, null];`。因为此时第二项已经有值，且遍历中当前元素大于子序列最小元素且小于子序列第二大元素，所以可以将第二大元素更新为`nums[2]`，避免错过子序列后两个递增值都小于`nums[1]`的情况。
5. 当前索引`i = 4`，`∵ nums[4] < incArr[0]; ∴ incArr[0] = nums[4], incArr = [-3, 5, null]`。因为我们只需要求得原始数组中是否存在三元递增子序列，而不需要知道三元递增子序列的内容是什么。所以在此需要将`incArr[0]`更新，避免错过一些特殊情况（这种情况暂时还没想好怎么描述，类似于避免错过在`-3`到`7`之间出现了`[-3, -2, -1]`这种情况）。
6. 当前所以`i = 5`，`∵ nums[5] > incArr[1]; ∴ incArr[2] = nums[5], incArr = [-3, 5, 7]`。虽然真实的三元递增数组并不是`[-3, 5, 7]`，而是`[4, 6, 7]`或者`[2, 6, 7]`等情况，但是这样并不会影响三元递增数组是否存在的结果。
#### 该思路应该适用于求无排序数组中是否存在n元递增数组，只需在原始数组遍历中的将当前值`num[i]`与`incArr`各项循环对比更新即可