思路

如果我们把众数记为 +1+1，把其他数记为 -1−1，将它们全部加起来，显然和大于 0，从结果本身我们可以看出众数比其他数多。

算法

我们首先给出 Boyer-Moore 算法的详细步骤：

我们维护一个候选众数 candidate 和它出现的次数 count。初始时 candidate 可以为任意值，count 为 0；

我们遍历数组 nums 中的所有元素，对于每个元素 x，在判断 x 之前，如果 count 的值为 0，我们先将 x 的值赋予 candidate，随后我们判断 x：

如果 x 与 candidate 相等，那么计数器 count 的值增加 1；

如果 x 与 candidate 不等，那么计数器 count 的值减少 1。

在遍历完成后，candidate 即为整个数组的众数。

我们举一个具体的例子，例如下面的这个数组：

[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]
在遍历到数组中的第一个元素以及每个在 | 之后的元素时，candidate 都会因为 count 的值变为 0 而发生改变。最后一次 candidate 的值从 5 变为 7，也就是这个数组中的众数。

Boyer-Moore 算法的正确性较难证明，这里给出一种证明思路：

设真正的众数为 maj，且在遍历数组 nums 的某一任意时刻的候选众数为 c。此时我们遍历数组 nums 中的下一个元素 x。如果 x == maj，那么无论 c 是否等于 maj，计数器的值都会加 1（仔细思考一下，为什么？）；如果 x != maj，那么计数器在 x == c 时会加 1，在 x != c 时会减 1。由于 maj 是数组 nums 的众数，出现的次数超过一半，因此在最后计数器 count 的值一定大于 0（因为在超过一半的遍历中，计数器的值都加 1）。同理，如果我们以非众数的任一整数作为基准，可以用同样的方法得到，在最后计数器 count 的值一定小于 0，但 count 在我们的算法步骤中显然不会小于 0，因此最终的 candidate 一定就是 maj。

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let val = nums[0];
    let count = 1;
    const len = nums.length;
    for (let i = 1; i < len; i++) {
        if (count === 0) {
            val = nums[i];
        }
        count += (val === nums[i]) ? 1 : -1;
    }
    return val;
};
```