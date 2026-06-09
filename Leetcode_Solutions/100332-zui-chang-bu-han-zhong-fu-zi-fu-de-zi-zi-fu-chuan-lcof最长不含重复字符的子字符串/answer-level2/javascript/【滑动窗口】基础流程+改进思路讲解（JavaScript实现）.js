// ## 题目分析

// 留意最长子串和子序列不是一个概念。例如对“pwwkew”来说，最长子串是“wke”，“pwke”是其中一个子序列。

// 在不考虑时间的情况下，直接暴力法对所有的子串进行检查。复杂度是$O(N^3)$，会超时错误。

// ## 解法 1: 滑动窗口

// 准备 2 个指针 i、j，i 指向窗口左边，j 指向右边。指针每次可以向前“滑动”一个位置，它们之间的区域就是“窗口”。

// 整体流程如下：

// 1.  准备哈希表 map。key 是 char，value 是 boolean，代表字符 char 是否出现在滑动窗口内
// 2.  i 和 j 初始化为 0，结果 ans 初始化为 0
// 3.  检查`s[j]`是否出现过：
//     -   没有出现过，扩大窗口：记录`s[j]`，指针 j 向右滑动一格，更新 ans
//     -   出现过，缩小窗口：指针 i 向右移动一格，`map[s[i]]`更新为 false
// 4.  如果 i 和 j 没有越界，回到 step3，否则返回 ans

// 代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
// 原文地址：https://xxoo521.com/2020-03-11-length-of-substring/

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    const length = s.length;
    const map = {}; // char => boolean 代表着char是否在目前的窗口内
    let i = 0,
        j = 0;
    let ans = 0;
    while (i < length && j < length) {
        if (!map[s[j]]) {
            ans = Math.max(j - i + 1, ans);
            map[s[j]] = true;
            ++j;
        } else {
            // 如果char重复，那么缩小滑动窗口，并更新对应的map
            map[s[i]] = false;
            ++i;
        }
    }

    return ans;
};
// ```

// 由于整个过程就是“推着”滑动窗口从左到右，时间复杂度是$O(N)$，空间复杂度是$O(N)$。

// ## 解法 2: 优化后的滑动窗口

// 在解法 1 的流程中的第 3 步，如果`s[j]`出现在滑动窗口内，采用的做法是左边逐步缩小滑动窗口。事实上，不需要逐步缩小。假设滑动窗口内和`s[j]`相同字符下标是 j'，那么直接跳过`[i, j']` 范围即可。

// 为了做到“跳动优化”，需要改造一下对哈希表 map 的用法：key 还是 char；value 变为 int，记录 char 对应的下标。

// 整体代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
// 原文地址：https://xxoo521.com/2020-03-11-length-of-substring/

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    const length = s.length;
    const map = new Map();
    let i = 0,
        j = 0;
    let ans = 0;
    while (i < length && j < length) {
        // 容易理解：检查s[j]是否出现过，并且s[j]重复的字符是否在当前的滑动窗口中
        if (map.has(s[j]) && map.get(s[j]) >= i) {
            i = map.get(s[j]) + 1;
        }
        ans = Math.max(j - i + 1, ans);
        map.set(s[j], j);
        ++j;
    }
    return ans;
};
// ```

// ## 更多资料

// **整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
