
首先前序/后序遍历 + 中序遍历可以重建二叉树。题目考察的就是前序+中序来重建二叉树，后序+中序的思路是类似的。

## 例子与思路

假设有二叉树如下：

```
    1
   / \
  2   3
 / \
4   5
```

它的前序遍历的顺序是：`1 2 4 5 3`。中序遍历的顺序是：`4 2 5 1 3`

因为前序遍历的第一个元素就是当前二叉树的根节点。那么，这个值就可以将中序遍历分成 2 个部分。在以上面的例子，中序遍历就被分成了 `4 2 5` 和 `3` 两个部分。`4 2 5`就是左子树，`3`就是右子树。

最后，根据左右子树，继续递归即可。

## 代码实现

```javascript
// ac地址：https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
// 原文地址：https://xxoo521.com/2019-12-21-re-construct-btree/

/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    if (!preorder.length || !inorder.length) {
        return null;
    }

    const rootVal = preorder[0];
    const node = new TreeNode(rootVal);

    let i = 0; // i有两个含义，一个是根节点在中序遍历结果中的下标，另一个是当前左子树的节点个数
    for (; i < inorder.length; ++i) {
        if (inorder[i] === rootVal) {
            break;
        }
    }

    node.left = buildTree(preorder.slice(1, i + 1), inorder.slice(0, i));
    node.right = buildTree(preorder.slice(i + 1), inorder.slice(i + 1));
    return node;
};
```


## 更多资料

-   **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**
