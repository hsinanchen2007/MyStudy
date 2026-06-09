
// ## 解法 1: 前序遍历（递归）

// 算法实现思路是：

// -   每次来到新节点，将节点放入当前保存的路径
// -   检查节点是否是叶节点：
//     -   是：将路径放入结果中
//     -   不是：继续遍历左子树和右子树

// 上面整个过程就是一个前序遍历，但在遍历的过程中，动态地维护了当前路径与总和的信息。

// 在实现过程中需要注意的是，JavaScript 中传入数组做参数，函数内拿到的是数组的引用，不是深拷贝。代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
// 原文地址：https://xxoo521.com/2020-02-04-btree-find-path/

/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number[][]}
 */
var pathSum = function(root, sum) {
    if (!root) {
        return [];
    }
    const pathes = [];
    __pathSum(root, sum, pathes, []);
    return pathes;
};

function __pathSum(root, sum, pathes, path) {
    if (!root) {
        return;
    }

    path = [...path, root.val]; // 深拷贝

    if (!root.left && !root.right && root.val === sum) {
        pathes.push(path);
        return;
    }

    __pathSum(root.left, sum - root.val, pathes, path);
    __pathSum(root.right, sum - root.val, pathes, path);
}
// ```

// ## 解法 2: 非递归遍历

// 这里可以借助栈，改造成非递归前序遍历。从而减少运行时间。

// 为了方便表示节点信息，栈中的元素是形如`(node, 剩余路径和, 节点路径组成的数组)`这样的元祖。

// 整体的处理流程是：

// -   取出栈顶的元祖：节点、剩余路径和、路径
// -   如果当前节点是叶节点，且剩余路径和等于节点的 val，那么将路径放入结果中
// -   如果右节点不为空，将（右节点，剩余路径和 - 右节点值，路径+右节点）放入栈中
// -   如果做节点不为空，处理过程和右节点一样

// 注意，为什么先处理右节点而不是左节点？先遍历左和右都可以。但是因为用的***的 oj 平台，这里要求“数组长度大的数组靠前”，先遍历左节点就是 oc 不了。

// 代码实现如下：

// ```javascript
// ac地址：https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
// 原文地址：https://xxoo521.com/2020-02-04-btree-find-path/

/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number[][]}
 */
var pathSum = function(root, sum) {
    if (!root) {
        return [];
    }

    const statck = [[root, sum, [root.val]]];
    const result = [];

    while (statck.length) {
        const [node, num, path] = statck.pop();

        if (!node.left && !node.right && node.val === num) {
            result.push(path);
        }

        if (node.right) {
            statck.push([
                node.right,
                num - node.val,
                [...path, node.right.val]
            ]);
        }
        if (node.left) {
            statck.push([node.left, num - node.val, [...path, node.left.val]]);
        }
    }

    return result;
};
// ```

// ## 更多资料

// -   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
// -   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
// -   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
