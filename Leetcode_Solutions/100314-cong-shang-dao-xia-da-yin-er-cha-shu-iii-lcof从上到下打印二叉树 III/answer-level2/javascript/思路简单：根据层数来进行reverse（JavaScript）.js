
// ## 题目分析

// 这题几乎和[「LeetCode 102.二叉树的层次遍历」](https://xxoo521.com/2020-02-20-level-travel/)完全一样，唯一不同的是行数为奇数的从左到右打印，行数为偶数的从右到左打印。

// ## 解法：层序遍历

// 借助 level 变量标记层数，当 level 为偶数的时候，镜像翻转遍历结果。代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
// 原文地址：https://xxoo521.com/2020-02-20-level-travel-3/

/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if (!root) return [];
    const queue = [root];
    const res = [];
    let level = 0; // 代表当前层数
    while (queue.length) {
        res[level] = []; // 第level层的遍历结果

        let levelNum = queue.length; // 第level层的节点数量
        while (levelNum--) {
            const front = queue.shift();
            res[level].push(front.val);
            if (front.left) queue.push(front.left);
            if (front.right) queue.push(front.right);
        }
        // 行号是偶数时，翻转当前层的遍历结果
        if (level % 2) {
            res[level].reverse();
        }

        level++;
    }
    return res;
};
// ```

// 时间复杂度是$O(N)$，空间复杂度是$O(N)$。

// ## 更多资料

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
