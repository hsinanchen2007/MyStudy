### 102.Binary Tree Level Order Traversal

解析: 该题考察的是`树的广度遍历(BFS)`, 运用到了`队列`相关知识;

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
 * @return {number[][]}
 */
var levelOrder = function(root) {
  const printArr = []
  if (!root) return printArr
  const list = []
  list.push({ node: root, level: 0 })
  while (list.length > 0) {
    const { node, level } = list.shift()
    if (!printArr[level]) {
      printArr[level] = []
    }
    printArr[level].push(node.val)
    node.left && list.push({ node: node.left, level: level + 1 })
    node.right && list.push({ node: node.right, level: level + 1 })
  }
  return printArr
}
```

![](https://pic.leetcode-cn.com/34fb4e5f125e12ea170f59a21e679144e341305e41364fa7732b472ae51c019f.jpg)

### Similar Title

102、107、103、199

> 为确保内容的实时、准确性, 可以查看[JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/LeetCode/README.md)