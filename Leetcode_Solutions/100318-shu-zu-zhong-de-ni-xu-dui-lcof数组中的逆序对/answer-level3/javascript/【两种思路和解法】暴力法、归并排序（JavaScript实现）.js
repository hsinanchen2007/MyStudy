
// ## 解法 1: 暴力法（TLE）

// 直接双重循环，挨个检查是否为逆序对。代码实现比较简单：

// ```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var reversePairs = function(nums) {
    let res = 0;
    const length = nums.length;
    for (let i = 0; i < length; ++i) {
        for (let j = i + 1; j < length; ++j) {
            nums[i] > nums[j] && ++res;
        }
    }

    return res;
};
// ```

// 时间复杂度是$O(N^2)$。在 leetcode 上会 TLE，无法通过（毕竟这是道标注「困难」的题目）。

// ## 解法 2: 归并排序（正确解法）

// 这题的正确解法是要借助归并排序的思路，在归并的过程中，快速统计逆序对。这种解法比较难想到，但是应用归并排序的题目真的不多，所以这题很有研究和收藏意义。

// 核心的解决逻辑都封装在 findInversePairNum 函数中。它的职能就是统计数组`arr[start, end]`范围中的逆序对，并且统计完后，`arr[start, end]`范围中的元素会被排序（这点和归并排序的过程一样）。

// 那么函数又是如何快速统计逆序对的呢？大体过程如下：

// -   递归调用，拿到左子数组和右子数组的逆序对（此时，左子数组和右子数组也都排序完成了）
// -   指针 i 和 j 分别指向左子数组和右子数组的最右侧，此时会有 2 种情况：
//     -   `arr[i] > arr[j]`：那么说明`arr[i]`大于右子数组中所有元素，逆序对增加`j - start - length`，向左边移动指针 i
//     -   `arr[i] <= arr[j]`: 对`arr[i]`来说，不存在逆序对，向左边移动指针 j
// -   i 和 j 遍历完各自数组后，最后返回逆序对之和即可

// 代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
// 原文地址：https://xxoo521.com/2020-03-12-reverse-pairs/
/**
 * @param {number[]} nums
 * @return {number}
 */
var reversePairs = function(nums) {
    return findInversePairNum(nums, 0, nums.length - 1);
};

/**
 * @param {number[]} arr
 * @param {number} start
 * @param {number} end
 */
function findInversePairNum(arr, start, end) {
    if (start >= end) return 0;

    const copy = new Array(end - start + 1);
    const length = Math.floor((end - start) / 2); // 左数组长度
    const leftNum = findInversePairNum(arr, start, start + length);
    const rightNum = findInversePairNum(arr, start + length + 1, end);

    let i = start + length;
    let j = end;
    let copyIndex = end - start;
    let num = 0;
    while (i >= start && j >= start + length + 1) {
        if (arr[i] > arr[j]) {
            num += j - start - length;
            copy[copyIndex--] = arr[i--];
        } else {
            copy[copyIndex--] = arr[j--];
        }
    }

    while (i >= start) {
        copy[copyIndex--] = arr[i--];
    }

    while (j >= start + length + 1) {
        copy[copyIndex--] = arr[j--];
    }

    for (let k = start; k <= end; ++k) {
        arr[k] = copy[k - start];
    }

    return num + leftNum + rightNum;
}
// ```

// 时间复杂度是$O(NlogN)$，空间复杂度是$O(N)$。如果还是觉得不好理解，可以以数组 7、5、6、4 为例，按照前面过程，手动计算一下。

// ## 更多资料

// **整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
