
// 为了方便说明，先看两个例子。

// ### 例子 1

// 下图是第一个例子，可以看到 B 是 A 的子结构。

// ![](https://pic.leetcode-cn.com/a278a06ffe086ec145e197e4f9523727dca2a7c4df9e2ce87f10b1dc56c25e80.jpg)

// 第一个例子的判断逻辑是：

// -   比较当前节点值
// -   递归比较左右节点的值
// -   直到遍历完 B 树

// ### 例子 2

// 下图是第二个例子，可以看到 B 也是 A 的子结构。

// ![](https://pic.leetcode-cn.com/22485a07d134e496b30779af5ab668288859bf3e9f24a043ac919059eb11845c.jpg)

// 但是 A 的根节点和 B 的根节点并不相同。因此对于这种情况，需要对 A 树进行递归遍历。如果 B 是 A 的左子树或者右子树的子结构，那么也是可以的。

// ### 代码实现

// 设计两个函数：

// -   isSubStructure 的职能：判断 B 是否是 A 的子结构。是，返回 true；否则，尝试 A 的左右子树
// -   isSubTree 的职能：封装“判断 B 是否是 A 的子结构”的具体逻辑。

// ```javascript
// ac地址：https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
// 原文地址：https://xxoo521.com/2020-01-13-subtree/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} A
 * @param {TreeNode} B
 * @return {boolean}
 */
var isSubStructure = function(A, B) {
    // 题目约定：约定空树不是任意一个树的子结构
    if (!A || !B) {
        return false;
    }

    return (
        isSubTree(A, B) ||
        isSubStructure(A.left, B) ||
        isSubStructure(A.right, B)
    );
};

function isSubTree(pRoot1, pRoot2) {
    // B树遍历完了，说明B是A的子结构
    if (!pRoot2) {
        return true;
    }
    // A遍历完了，但是B还没有遍历完，那么B肯定不是A的子结构
    if (!pRoot1) {
        return false;
    }

    if (pRoot1.val !== pRoot2.val) {
        return false;
    }

    return (
        isSubTree(pRoot1.left, pRoot2.left) &&
        isSubTree(pRoot1.right, pRoot2.right)
    );
}
// ```

// ### 更多资料

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
