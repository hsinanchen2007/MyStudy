### 107.Binary Tree Level Order Traversal II

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
var levelOrderBottom = function(root) {
  const printArr = []
  if (!root) return printArr
  const list = []
  list.push({ node: root, level: 0 })
  while (list.length > 0) {
    const { node, level } = list.shift()
    if (!printArr[level]) {
      printArr.unshift([])
    }
    printArr[0].push(node.val)
    node.left && (list.push({ node: node.left, level: level + 1 }))
    node.right && (list.push({ node: node.right, level: level + 1 }))
  }
  return printArr
}
```

### Similar Title

102(Sister Title)、107、103、199

> 为确保内容的实时、准确性, 可以查看[JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/LeetCode/README.md)