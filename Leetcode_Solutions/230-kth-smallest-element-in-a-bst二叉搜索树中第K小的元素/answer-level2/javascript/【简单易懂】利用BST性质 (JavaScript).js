
## 解题关键：利用 BST 性质

根据二叉搜索树（BST）的性质：节点的权重大于左节点的权重，大于右节点的权重。因此，对 BST 进行中序遍历，就是按从小到大的顺序访问树中的元素。

解题关键是：在中序遍历过程中使用一个变量来记录当前节点被访问的次序。

代码如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
// 原文地址：https://xxoo521.com/2020-03-05-kth-smallest-element-in-a-bst/
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    let i = 0;
    let val = null;
    travel(root);
    return val;

    function travel(node) {
        node.left && travel(node.left);

        if (++i === k) {
            val = node.val;
            return;
        }

        node.right && travel(node.right);
    }
};
```

## 更多资料

**若有错误，欢迎指正。若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer + Leetcode 题解](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
