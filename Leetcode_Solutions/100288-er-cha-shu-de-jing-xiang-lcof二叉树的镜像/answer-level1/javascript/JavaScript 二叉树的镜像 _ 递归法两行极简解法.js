
![3IHP5q.png](https://pic.leetcode-cn.com/6a08202bfef471c3436948cfac70b0d6529cefd722a2cff105bd32893180c386.png)

## 思路

- 二叉树的性质导致了它非常适合递归法，此题若把子树看成一个整体，则所有的镜像交换过程都是相同的，所以非常简单
- 使用了 ES6 的解构赋值语法`[a, b] = [c, d]`，利用这个小技巧实现元素的交换。（当然，速度上不如使用中间变量进行交换）
- && 运算符如果前面的条件为 false，则后面的条件不会执行（使用单行 if 语句也是可以的）
- root 为 null 无需单独 return null，直接 return root 即可

## 代码

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var mirrorTree = function(root) {
    root && ([root.left, root.right] = [mirrorTree(root.right), mirrorTree(root.left)]);
    return root;
};
```

## 性能更好的交换

```js
var mirrorTree = function(root) {
    if (root) {
        const tmp = root.left;
        root.left = mirrorTree(root.right);
        root.right = mirrorTree(tmp);
    }
    return root;
};
```

## 其他

我的 GitHub [@ceynri](https://github.com/ceynri) 欢迎访问~
