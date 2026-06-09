
执行用时 :176 ms, 在所有 javascript 提交中击败了98.62%的用户

### 解题思路

由于题目说明了不能有重复的数组, 但是每一个数组中是可以有相同的数字的.

1. 考虑输入的数组长度小于3的情况;
2. 先将数组从小到大排序;
3. 利用`for`循环以`nums[i]`为基点数进行遍历;
4. 在遍历时定义两个起点, 最左侧`left (i + 1)`和最右侧`right (nums.length - 1)`;
5. 每次计算`nums[i] + nums[left] + nums[right]`的值`sum`;
6. 若`sum`大于`0`则`right`向左移, 即`right--`;
7. 若`sum`小于`0`则`left`向右移, 即`left++`;
8. 若`sum`等于0, 则证明找到了一组数, 依次移动两个起点, 但是每次移动的时候要考虑是否和上一项相等.

### coding
```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    if (!nums || nums.length < 3) return []
    nums = nums.sort((a, b) => a - b);
    let sum = 0; // 三个数的和
        result = [];
    for (let i = 0; i < nums.length; i++) {
        if (i && nums[i] === nums[i - 1]) continue; // 若当前这一项和上一项相等则跳过
        let left = i + 1;
        let right = nums.length - 1;
        while (left < right) {
            sum = nums[i] + nums[left] + nums[right];
            if (sum > 0) {
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                result.push([nums[i], nums[left++], nums[right--]]);
                while (nums[left] === nums[left - 1]) { // 一直找到不相同的那个坐标
                    left++;
                }
                while (nums[right] === nums[right + 1]) {
                    right--;
                }
            }
        }
    }
    return result;
};
```