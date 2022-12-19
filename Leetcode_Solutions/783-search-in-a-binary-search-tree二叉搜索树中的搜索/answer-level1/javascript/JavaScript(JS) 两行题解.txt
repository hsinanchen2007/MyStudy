### 解题思路
简单的两行题解

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} val
 * @return {TreeNode}
 */
var searchBST = function (root, val) {
    if (!root || root.val === val) return root
    return root.val < val ? searchBST(root.right, val) : searchBST(root.left, val);
};
```
![搜索框传播样式-标准色版.png](https://pic.leetcode-cn.com/5b693dce2ea930fe7d095fbb126cc9e8b0d109de3e59c4f09c898d62a09d7a9b-%E6%90%9C%E7%B4%A2%E6%A1%86%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
