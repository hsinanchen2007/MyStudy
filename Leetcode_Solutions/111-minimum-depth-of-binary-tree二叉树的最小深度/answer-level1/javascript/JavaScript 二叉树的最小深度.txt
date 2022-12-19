> 本来打算直接在「递归获取二叉树深度」的基础上将`Math.max`改成`Math.min`来做的，结果发现自己还是太天真了。这里的最小深度是从根节点到叶子节点的最少节点数量。而叶子节点指的是`left`和`right`均为`null`的节点。

```js
function minDepth(root) {
    if (root === null) return 0;
    if (!root.left&&!root.right) return 1;//当前节点为叶子节点时
    if (root.left&&!root.right) return 1+minDepth(root.left);//只有一个字节点时 减枝
    if (!root.left&&root.right) return 1+minDepth(root.right);//只有一个字节点时 减枝
    return 1+Math.min(minDepth(root.left),minDepth(root.right)) //存在两个字节点
}
```
![](https://pic.leetcode-cn.com/b43c82b5d1bd4a39e5fe5b3effce0ff82be81daf5bebe7aeaa81f7896e875f90-file_1565799268749)