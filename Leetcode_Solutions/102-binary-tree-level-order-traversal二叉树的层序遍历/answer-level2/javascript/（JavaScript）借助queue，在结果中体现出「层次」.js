
// ## 题目分析

// 从题目中可以看到，本题考察的是二叉树的层序遍历，并且在结果中要体现出“层次”。

// ## 思路

// 稍微改变一下对队列的使用，就可以在遍历过程中体现出层次，大致过程如下：

// -   初始化 queue，用于存储当前层的节点
// -   检查 queue 是否为空
//     -   如果不为空：依次遍历当前 queue 内的所有节点，检查每个节点的左右子节点，将不为空的子节点放入 queue，继续循环
//     -   如果为空：跳出循环

// 在上面的思路上，稍微改造下就可以了。代码如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
// 原文地址：https://xxoo521.com/2020-02-20-level-travel/

/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if (!root) return [];
    const queue = [root];
    const res = []; // 存放遍历结果
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
