
// ## 解法 1: 递归

// 递归的写法非常直观。对于一棵二叉树来说，它的高度等于左右子树的高度最大值，加上 1。

// 代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
// 原文地址：https://xxoo521.com/2020-03-22-max-depth/
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    if (!root) return 0;
    return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
};
// ```

// ## 解法 2: 层序遍历

// 按照二叉树的“层”去遍历，最后返回层的数目。这题和[《剑指 offer - 从上到下打印二叉树 III - JavaScript》](https://xxoo521.com/2020-02-20-level-travel-3/)思路完全一样。

// 细节请看代码注释，代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
// 原文地址：https://xxoo521.com/2020-03-22-max-depth/
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    if (!root) return 0;
    let res = 0;
    const queue = [root];
    while (queue.length) {
        let levelNum = queue.length; // 当前层中二叉树的节点数量
        ++res;
        // 依次将下一层的二叉树节点放入队列
        while (levelNum--) {
            const node = queue.shift();
            if (node.left) queue.push(node.left);
            if (node.right) queue.push(node.right);
        }
    }
    return res;
};
// ```

// ## 更多资料

// **整理不易，若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
