
// ## 题目分析

// 题目和示例都提示了，没要求“保持偶数和偶数之间的相对位置不变”。例如对 `[1,2,3,4]` 来说，`[1,3,2,4]` 和 `[3,1,2,4]` 都是正确答案。

// ## 解法 1:开辟新空间

// 此过程需要循环 2 次，时间复杂度 O(N), 空间复杂度 O(N)。过程如下：

// -   第一次循环依次找到偶数和奇数，并且将其分别存放到新开辟的空间中
// -   第二次循环将存放偶数和奇数的空间“连接”在一起

// 代码如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
// 原文地址：https://xxoo521.com/2020-01-01-tiao-zheng-shu-zu/
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var exchange = function(nums) {
    const arr = []; // 奇数数组
    const brr = []; // 偶数数组
    nums.forEach(item => {
        item % 2 ? arr.push(item) : brr.push(item);
    });

    return arr.concat(brr);
};
// ```

// ## 解法 2: 双指针交换

// 可以利用“双指针”，分别是指向数组头部的指针 i，与指向数组尾部的指针 j。过程如下：

// -   i 向右移动，直到遇到偶数；j 向左移动，直到遇到奇数
// -   检查 i 是否小于 j，若小于，交换 i 和 j 的元素，回到上一步骤继续移动；否则结束循环

// 时间复杂度是 O(N),空间复杂度是 O(1)。代码如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
// 原文地址：https://xxoo521.com/2020-01-01-tiao-zheng-shu-zu/
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var exchange = function(nums) {
    const length = nums.length;
    if (!length) {
        return [];
    }

    let i = 0,
        j = length - 1;
    while (i < j) {
        while (i < length && nums[i] % 2) i++;
        while (j >= 0 && nums[j] % 2 === 0) j--;

        if (i < j) {
            [nums[i], nums[j]] = [nums[j], nums[i]];
            i++;
            j--;
        }
    }

    return nums;
};
// ```

// ## 拓展思考：基于插入排序思路

// 如果题目中的要求，加上“保证奇数和奇数，偶数和偶数之间的相对位置不变”这个条件，那么解法是什么呢？

// 这种思路和插入排序相似，时间复杂度 O(N^2)，空间复杂度 O(1)。这里时间复杂度主要浪费在“保持偶数和奇数原相对位置不变”这个要求上。

// 整体的思路：

// -   指针 i 从 0 开始向右移动，如果遇到奇数，继续移动；遇到偶数，停下来，并进入循环
//     -   设置新指针 j = i + 1，指针 j 向右移动，遇到偶数，继续移动；遇到奇数，停下来，并进入下一步
//     -   将数组`[i, j - 1]` 的元素整体向右位移 1 位，然后将 j 上的元素赋给 i 上的元素
// -   检测是否遍历完成，未完成则回到第一步

// ```javascript
// 原文地址：https://xxoo521.com/2020-01-01-tiao-zheng-shu-zu/
// ac地址：https://www.***.com/practice/beb5aa231adc45b2a5dcc5b62c93f593

/**
 * @param {number[]} array
 * @return {number[]}
 */
function reOrderArray(array) {
    const length = array.length;
    if (!length) {
        return [];
    }

    let i = 0;
    while (i < length) {
        if (array[i] % 2 === 0) {
            // 如果指针i对应的元素是偶数
            // 那么就需要找到其后出现的第一个奇数
            // 然后和指针i的元素进行交换
            let j = i + 1;
            for (; j < length && array[j] % 2 === 0; ++j) {}
            if (j === length) {
                break;
            } else {
                // 整体右移，保证原元素的相对位置不变
                const tmp = array[j];
                for (let k = j; k > i; k--) {
                    array[k] = array[k - 1];
                }
                array[i] = tmp;
            }
        }
        i++;
    }

    return array;
}
// ```

// ## 更多资料

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
