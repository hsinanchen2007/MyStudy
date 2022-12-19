#### 递归

按照根-左-右的方式进行遍历

```
/**
 * 先序遍历：根-左-右
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function(root) {
  let arr = []
  var preorder = function(node, arr) {
    if (node === null) return arr
    arr.push(node.val)
    preorder(node.left, arr)
    preorder(node.right, arr)
  }
  preorder(root, arr)
  return arr
};
```

#### 迭代-1

从根节点开始，每次迭代弹出当前栈顶元素，并将其孩子节点压入栈中，先压右孩子再压左孩子。

```
/**
 * 先序遍历：迭代方式
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function(root) {
  var stack = [root]
  var number = []
  while(stack.length > 0) {
    var node = stack.pop()
    number.push(node.val) 
    if (node.right !== null) {
      stack.push(node.right)
    }
    if (node.left !== null) {
      stack.push(node.left)
    }
  }
  return number
};
```