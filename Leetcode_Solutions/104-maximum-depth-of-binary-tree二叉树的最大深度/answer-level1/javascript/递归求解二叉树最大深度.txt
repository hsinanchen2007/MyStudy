## 题目剖析

> 给定一个二叉树，找出其最大深度。
> 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

## 解题思路

尝试把这道题讲得更加清晰明白一些。
不妨假设有一种极端的二叉树，右节点全部为空（退化成链表）

![image.png](https://pic.leetcode-cn.com/578971fe3d95ccfad37b0f26c2cdb29a8a0cbccfdd4071ef36b3bb96db0f5eb4-image.png)  

显然，如果我们要拿到这个特殊的二叉树的深度的话，可以从底部递增，最后返回这个值👇

![image.png](https://pic.leetcode-cn.com/15b21ef6609cec3a223fc7d108db7713e96aa8fc01036540048fbe2138960b9c-image.png)

我们第一版的代码可以是这样👇

```javascript
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    if (!root) {
        return 0
    }
    return maxDepth(root.left) + 1
};
```

同样的，如果左子树全部为空，代码可以这样写👇

```javascript
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    if (!root) {
        return 0
    }
    return maxDepth(root.right) + 1
};
```
根据上面的代码，左右子树的深度我们都能拿到。在不只考虑极端情况的时候，其实我们只要比较左右子树的深度就行了。

## 示例代码

```javascript
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    if (!root) {
        return 0
    }
    return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1
};
```