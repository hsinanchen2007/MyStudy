一个二叉搜索树的每个节点必须都满足这个条件：任意节点的值必须大于其左子树的最右节点；同时小于右子树的最左节点。
从根节点开始检查，一旦发现不满足则返回false。

```javascript
var isValidBST = function(root) {
  if (root === null) return true
  const left = rightest(root.left) // 左子树最右节点
  const right = leftest(root.right) // 右子树最左节点
  if (left && left.val >= root.val) return false
  if (right && right.val <= root.val) return false
  return isValidBST(root.left) && isValidBST(root.right)
};

function rightest(node) {
  while (node && node.right) node = node.right
  return node
}

function leftest(node) {
  while (node && node.left) node = node.left
  return node
}
```