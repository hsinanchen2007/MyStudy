>执行用时 :72 ms, 在所有 JavaScript 提交中击败了98.64%的用户

### Print all permutations in sorted (lexicographic) order
我们应该先了解如何`print all permutations in sorted (lexicographic) order`。例如我们有一个数组`[1,2,3,4,5]`，其`permutations in sorted (lexicographic) order`应该是:
```
[ 1, 2, 3, 4, 5 ]
[ 1, 2, 3, 5, 4 ]
[ 1, 2, 4, 3, 5 ]
[ 1, 2, 4, 5, 3 ]
[ 1, 2, 5, 3, 4 ]
[ 1, 2, 5, 4, 3 ]
[ 1, 3, 2, 4, 5 ]
...
...
[ 5, 4, 2, 1, 3 ]
[ 5, 4, 2, 3, 1 ]
[ 5, 4, 3, 1, 2 ]
[ 5, 4, 3, 2, 1 ]
```
根据其定义以及例子的提示，我们生成每个序列的步骤应该是:

* 首先`sort`给定的`array`，并输出第一次数组（排序的第一个）。
* 开始循环产生下一个`higher permutation`。
     * 从右边开始检查，找到第一个比右值小的数字，设为`first number`。
     * 从`first number`的右边开始，查找比`first number`大，而且相差最小的数字为`second number`。
     * 交换`first number`和`second number`。
     * 将`first number`之后的数组，即`nums[first + 1]`至`nums[length - 1]`，作升序排序。
* 继续上面的循环直至数组为降序排序。

``` JavaScript
var printPermutationInOrder = function (nums) {
    // 若需要排序
    nums.sort((a, b) => a - b);
    // 输出第一种排序
    console.log(nums);
    swap = function (nums, l) {
        let first = l,
            second = 0;
        // 2.1 从右侧开始寻找第一个比右值小的数字
        for (let i = nums.length - 2; i > l; i--) {
            if (nums[i] < nums[i + 1]) {
                first = i;
                break;
            }
        }
        // 2.2 从 first 右侧开始查找比 first 大，但是相差最小的数字
        second = first;
        let min = Infinity;
        for (let i = first + 1; i < nums.length; i++) {
            const sub = nums[i] - nums[first];
            if (sub > 0 && sub < min) {
                min = sub;
                second = i;
            }
        }
        // 2.3 交换 first 和 second
        [nums[first], nums[second]] = [nums[second], nums[first]];
        // 2.4 将 first 之后的数组按升序排序
        nums = nums.slice(0, first + 1).concat(nums.slice(first + 1, nums.length).sort((a, b) => a - b));
        // 输出当前排序
        console.log(nums);
        // 继续上面的循环直至剩余数组为升序排序
        for (let i = 0; i < nums.length - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                swap(nums, -1);
                break;
            }
        }
        return;
    }
    swap(nums, -1);
}
```

### Print next permutations in sorted (lexicographic) order

当我们已经可以输出序列之后，需要输出下一个序列，只是讲上面提到的第二步做一次即可。当然题目中要求我们当不存在下一个序列，即数组为降序排列时，输出升序的结果。

```JavaScript
/**
 * 
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function (nums) {
    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i] < nums[i + 1]) {
            let first = 0,
                second = 0,
                min = Infinity;
            for (let i = nums.length - 2; i > 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    first = i;
                    break;
                }
            }

            for (let i = first + 1; i < nums.length; i++) {
                const sub = nums[i] - nums[first];
                if (sub > 0 && sub < min) {
                    min = sub;
                    second = i;
                }
            }

            [nums[first], nums[second]] = [nums[second], nums[first]];

            for (let i = 0; i < nums.length - first; i++) {
                for (let j = first + 1; j < nums.length - i - 1; j++) {
                    if (nums[j] > nums[j + 1]) {
                        [nums[j], nums[j + 1]] = [nums[j + 1], nums[j]];
                    }
                }
            }

            return nums;
        }
    }

    return nums.sort((a, b) => a - b);
};
```