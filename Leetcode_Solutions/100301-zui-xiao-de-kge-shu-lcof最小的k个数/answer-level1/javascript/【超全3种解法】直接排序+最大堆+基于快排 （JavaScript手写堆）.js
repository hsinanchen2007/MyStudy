
// ## 题目分析

// 虽然这题在 leetcode 上标注的「简单」，但是本题还是很有研究意义的。本文介绍了 3 种解法，时间复杂度依次降低，都是基于经典的算法或者数据结构。

// ## 解法 1: 直接排序

// 先说最简单、最直观的做法：直接排序。将数组按照从小到大的顺序排序，并且返回前 k 个数字。代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
// 原文地址：https://xxoo521.com/2020-02-21-least-nums/

/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    return arr.sort((a, b) => a - b).slice(0, k);
};
// ```

// 使用高级排序（代码用的是快排），时间复杂度是$O(NlogN)$，空间复杂度是$O(logN)$。

// ## 解法 2: 最大堆

// 堆是一种非常常用的数据结构。最大堆的性质是：节点值大于子节点的值，堆顶元素是最大元素。利用这个性质，整体的算法流程如下：

// -   创建大小为 k 的最大堆
// -   将数组的前 k 个元素放入堆中
// -   从下标 k 继续开始依次遍历数组的剩余元素：
//     -   如果元素小于堆顶元素，那么取出堆顶元素，将当前元素入堆
//     -   如果元素大于/等于堆顶元素，不做操作

// 由于堆的大小是 K，空间复杂度是$O(K)$，时间复杂度是$O(NlogK)$。

// 由于 JavaScript 中没有堆，所以需要手动实现。代码如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
// 原文地址：https://xxoo521.com/2020-02-21-least-nums/
function swap(arr, i, j) {
    [arr[i], arr[j]] = [arr[j], arr[i]];
}

class MaxHeap {
    constructor(arr = []) {
        this.container = [];
        if (Array.isArray(arr)) {
            arr.forEach(this.insert.bind(this));
        }
    }

    insert(data) {
        const { container } = this;

        container.push(data);
        let index = container.length - 1;
        while (index) {
            let parent = Math.floor((index - 1) / 2);
            if (container[index] <= container[parent]) {
                break;
            }
            swap(container, index, parent);
            index = parent;
        }
    }

    extract() {
        const { container } = this;
        if (!container.length) {
            return null;
        }

        swap(container, 0, container.length - 1);
        const res = container.pop();
        const length = container.length;
        let index = 0,
            exchange = index * 2 + 1;

        while (exchange < length) {
            // 如果有右节点，并且右节点的值大于左节点的值
            let right = index * 2 + 2;
            if (right < length && container[right] > container[exchange]) {
                exchange = right;
            }
            if (container[exchange] <= container[index]) {
                break;
            }
            swap(container, exchange, index);
            index = exchange;
            exchange = index * 2 + 1;
        }

        return res;
    }

    top() {
        if (this.container.length) return this.container[0];
        return null;
    }
}

/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    const length = arr.length;
    if (k >= length) {
        return arr;
    }

    const heap = new MaxHeap(arr.slice(0, k));
    for (let i = k; i < length; ++i) {
        if (heap.top() > arr[i]) {
            heap.extract();
            heap.insert(arr[i]);
        }
    }
    return heap.container;
};
// ```

// ## 解法 3: 基于快速排序的 partition

// 解法 1 中使用了快速排序，但其实并需要对全部元素进行排序，题目只需要前 k 个元素。

// 回顾快速排序中的 partition 操作，可以将元素`arr[0]`放入排序后的正确位置，并且返回这个位置`index`。利用 partition 的特点，算法流程如下：

// -   如果`index = k`，说明第 k 个元素已经放入正确位置，返回前 k 个元素
// -   如果`k < index`，前 k 个元素在`[left, index - 1]`之间，缩小查找范围，继续查找
// -   如果`index < k`，前 k 个元素在`[index + 1, right]` 之间，缩小查找范围，继续查找

// 为了方便理解，可以使用`2, 8, 1, 1, 0, 11, -1, 0`这个例子在纸上画一下过程。

// 代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
// 原文地址：https://xxoo521.com/2020-02-21-least-nums/

/**
 *
 * @param {number[]} arr
 * @param {number} start
 * @param {number} end
 * @return {number}
 */
function partition(arr, start, end) {
    const k = arr[start];
    let left = start + 1,
        right = end;
    while (1) {
        while (left <= end && arr[left] <= k) ++left;
        while (right >= start + 1 && arr[right] >= k) --right;

        if (left >= right) {
            break;
        }

        [arr[left], arr[right]] = [arr[right], arr[left]];
        ++left;
        --right;
    }
    [arr[right], arr[start]] = [arr[start], arr[right]];
    return right;
}

/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    const length = arr.length;
    if (k >= length) return arr;
    let left = 0,
        right = length - 1;
    let index = partition(arr, left, right);
    while (index !== k) {
        if (index < k) {
            left = index + 1;
            index = partition(arr, left, right);
        } else if (index > k) {
            right = index - 1;
            index = partition(arr, left, right);
        }
    }

    return arr.slice(0, k);
};
// ```

// 时间复杂度是$O(N)$，空间复杂度是$O(N)$。

// ## 总结

// 不得不说 Leetcode 平台还是很准确的。下面第一张是解法 3 的运行结果，第二张是解法 2 的运行结果，解法 3 的时间效率更高。

// ![](https://pic.leetcode-cn.com/0cfb470c8a4c78bc9ec48344c7d81d5e5776f313630cdf7f796329a73f37af35.jpg)

// ![](https://pic.leetcode-cn.com/e1a8a0bd5f5061d2707a9b73e76dd7e5a6982de24a5fa3e7ea8f1b9eda47bd1a.jpg)

// 解法 2 中实现的堆不是最优的方法，有 2 点可以优化：

// -   swap 交换换成元素赋值。
// -   根绝数组创建堆的时候，可以从第一个非叶节点向上执行 shift_up 操作。这个过程是`heapify`。

// 不过本题考察重点不在这，所以就随手写了下堆的代码（主要是看的明白）。有兴趣可以看一下 C++标准库的实现。

// ## 更多资料

// **整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
