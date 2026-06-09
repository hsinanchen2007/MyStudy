
## 解法：改造中序遍历

根绝二叉搜索树的性质，中序遍历就是按照从小到大的顺序遍历节点。假设中序遍历结果是：1、2、3、4。那么根据题目要求，每个节点的值更新如下：

-   4 => 4
-   3 => 4 + 3
-   2 => 4 + 3 + 2
-   1 => 4 + 3 + 2 + 1

假如先遍历右节点，再遍历当前节点，最后遍历左节点。按照这种遍历顺序，之前遍历的节点都大于当前节点，**所以当前节点的新值就等于 之前遍历的节点的和 + 节点自身的值**。

代码实现如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/
// 原文地址：https://xxoo521.com/2020-03-06-binary-search-tree-to-greater-sum-tree/

/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var bstToGst = function(root) {
    let sum = 0; // 之前遍历的所有节点的和
    travse(root);
    return root;

    function travse(node) {
        node.right && travse(node.right);

        node.val += sum;
        sum = node.val;

        node.left && travse(node.left);
    }
};
```

## 更多资料

**若有错误，欢迎指正。若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer + Leetcode 题解](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**