## 题目描述

给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。  
例如，给定一个 ``3叉树``

![image.png](https://pic.leetcode-cn.com/f47078e949d759b45fe642bb31576571a65c02c95c7a694dd0bfa4751ee37545-image.png)

返回其层序遍历
```
[
    [1],
    [3,2,4],
    [5,6]
]
```

## 题目剖析

通常来说，这种逐层遍历的题目可以用 ``广度优先搜索`` 来做，而且解题形式比较通用，下面我们来梳理一下👇

以题目中给到的 ``3叉树`` 为例子

- 遍历第一层节点，存入数组
- 遍历第二层节点，存入数组
- ...
- 遍历完所有层的节点，将结果返回

这里的难点在于如何知道哪个节点到哪个节点之间才是一层😅

其实我们可以利用队列先进先出的特点来做这道题，比如说👇

- 遍历第一层节点，存入 ``a`` 数组，将第一层所有节点的子节点存到 ``b`` 数组
- 从 ``b`` 数组中拿到第二层节点，存入 ``a`` 数组，将第二层所有节点的子节点存到 ``b`` 数组
- ...
- 遍历完所有层的节点，将结果返回

## 示例代码

```javascript
/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if (!root) {
        return []
    }
    const res = [], queue = [root]
    while (queue.length) {
        const tmp = []
        let count = queue.length
        while (count--) {
            const root = queue.shift()
            tmp.push(root.val)
            for (let i = 0; i < root.children.length; i++) {
                queue.push(root.children[i])
            }
        }
        res.push(tmp.slice())
    }
    return res
};
```

## 最后

诚如上面所说，这道题也可以当作 ``广度优先遍历`` 的解题模板。就目前来看，遇到的这个类型的题目都可以网上套；当然，套模板的前是要对原理了然于胸，
盲目套模板只会「知其然而不知其所以然」
