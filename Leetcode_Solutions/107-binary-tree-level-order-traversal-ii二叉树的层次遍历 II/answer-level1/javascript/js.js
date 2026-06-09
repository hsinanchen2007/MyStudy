# 29 - 二叉树的层次遍历2

## 题目

给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

>     ​	3
>    ​	/ \
>   9     20
>     ​	 /      \	
>    ​	15     7

返回其自底向上的层次遍历为：

> [
>   [15,7],
>   [9,20],
>   [3]
> ]

## 解答

一开始的思路是，一层层pop出来，同一层的放在一个数组里面，最后reverse一下

思路是有了，就是写了半天写不出来。心想这还简单难度呢？

结果是要先把层次遍历的1写完，然后2就reverse一下。。。。

那自然是简单的很了！1可是中等难度呢！

### 迭代

```js
var levelOrderBottom = function (root) {
  if (!root) {
    return []
  }
  let stack = [root]
  let result = []
  let level = []
  let stack_tmp = []
  while (stack.length > 0) {
    for (let i = 0; i < stack.length; i++) {
      const cur = stack[i]
      level.push(cur.val)
      if (cur.left) {
        stack_tmp.push(cur.left)
      }
      if (cur.right) {
        stack_tmp.push(cur.right)
      }
    }
    result.push(level)
    stack = stack_tmp
    level = []
    stack_tmp = []
  }
  return result.reverse()
};
```

> Runtime: 68 ms, faster than 20.69% of JavaScript online submissions for Binary Tree Level Order Traversal II.
>
> Memory Usage: 34.9 MB, less than 66.05% of JavaScript online submissions for Binary Tree Level Order Traversal II.

### 递归

```js
var levelOrderBottom = function (root) {
  if (!root) {
    return []
  }
  let result = []
  const traverse = (node, level) => {
    if (node !== null) {
      result[level] ? result[level].push(node.val) : result[level] = [node.val];
      traverse(node.left, level + 1);
      traverse(node.right, level + 1);
    }
  }
  traverse(root, 0);
  return result.reverse();
};
```

> Runtime: 68 ms, faster than 20.69% of JavaScript online submissions for Binary Tree Level Order Traversal II.
>
> Memory Usage: 34.8 MB, less than 95.06% of JavaScript online submissions for Binary Tree Level Order Traversal II.