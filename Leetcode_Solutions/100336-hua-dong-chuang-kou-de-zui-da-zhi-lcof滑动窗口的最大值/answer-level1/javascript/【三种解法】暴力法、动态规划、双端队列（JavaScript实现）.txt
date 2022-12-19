
## 解法 1：暴力法

这题其实暴力法时间效率也很高，直接移动这个滑动窗口，每次统计窗口中的最大值即可。

代码实现：

```javascript
// ac地址：https://leetcode-cn.com/problems/sliding-window-maximum/
// 原文地址：https://xxoo521.com/2020-03-27-max-sliding-window/
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
    if (k <= 1) return nums;
    const res = [];
    for (let i = 0; i < nums.length - k + 1; ++i) {
        res.push(Math.max(...nums.slice(i, i + k)));
    }
    return res;
};
```

时间复杂度是$O(kN)$，其中 k 是滑动窗口的长度。空间复杂度是$O(N)$。

## 解法 2: 动态规划

[官方题解](https://leetcode-cn.com/problems/sliding-window-maximum/solution/hua-dong-chuang-kou-zui-da-zhi-by-leetcode-3/)中讲的很清楚了。

这里简单说下重要的点：将数组分成大小相等的块，每个块都可以理解为有两个数组 left 和 right。left 方向从左到右，right 相反。`left[i]`是指块从开始到下标 i 的最大元素，`right[j]`是指块从开始到下标 j 的最大元素。

假设滑动窗口的范围是`[i, j]`，很容易看出来，滑动窗口中的最大值就是 `max(right[i], left[j])`。

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/sliding-window-maximum/
// 原文地址：https://xxoo521.com/2020-03-27-max-sliding-window/
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
    if (k === 1) return nums;
    const length = nums.length;
    if (!length) return [];

    const left = new Array(length);
    const right = new Array(length);

    left[0] = nums[0];
    right[length - 1] = nums[length - 1];
    for (let i = 1; i < length; ++i) {
        if (i % k) {
            left[i] = Math.max(nums[i], left[i - 1]);
        } else {
            left[i] = nums[i];
        }

        let j = length - i - 1;
        if ((j + 1) % k) {
            right[j] = Math.max(nums[j], right[j + 1]);
        } else {
            right[j] = nums[j];
        }
    }

    const res = [];
    for (let i = 0; i < length - k + 1; i++) {
        res.push(Math.max(right[i], left[i + k - 1]));
    }
    return res;
};
```

这种做法时间复杂度比解法 1 更低，是$O(N)$。

## 解法 3: 双端队列

官方用[动画](https://leetcode-cn.com/problems/sliding-window-maximum/solution/shi-pin-jie-xi-shuang-duan-dui-lie-hua-dong-chuang/)演示了算法过程。

这里记录下重要的点：

-   双端队列中保存的是元素下标，方便判断元素是否在当前滑动窗口中
-   双端队列头元素对应的数字，就是当前滑动窗口的最大值
-   双端队列头尾出入元素的时间复杂度是$O(1)$
-   本题的双端队列用到功能，用链表就可以满足。C++的 STL 中的双端队列支持 insert，考虑了拷贝的高效型，实现上更复杂

为了方便，代码使用数组来模拟双端队列。代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/sliding-window-maximum/
// 原文地址：https://xxoo521.com/2020-03-27-max-sliding-window/
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function(nums, k) {
    if (k === 0) return [];
    const length = nums.length;
    if (length === 0) return [];

    const deque = [];
    for (let i = 0; i < k; ++i) {
        cleanDeque(deque, nums, i, k);
        deque.push(i);
    }

    const res = [];
    res.push(nums[deque[0]]);

    for (let i = k; i < length; ++i) {
        cleanDeque(deque, nums, i, k);
        deque.push(i);
        res.push(nums[deque[0]]);
    }

    return res;
};

/**
 * 刷新双端队列
 * @param {number[]} queue 双端队列
 * @param {number[]} nums 数组
 * @param {number} idx 当前元素下标
 * @param {number} k 滑动窗口大小
 */
function cleanDeque(queue, nums, idx, k) {
    // 如果双向队列中，包含不是滑动窗口内的数，直接出队
    if (queue.length && idx >= k + queue[0]) {
        queue.shift();
    }

    while (queue.length && nums[idx] > nums[queue[queue.length - 1]]) {
        queue.pop();
    }
}
```

由于每个元素只有 1 次机会进出双端队列，所以时间复杂度是$O(N)$。

## 更多资料

**整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
