### 递归法

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
 * @return {number[]}
 */
var postorderTraversal = function(root) {
  if (root) {
    return [...postorderTraversal(root.left), ...postorderTraversal(root.right), root.val]
  } else {
    return []
  }
}
```

### 颜色标记法(迭代法, 模拟系统栈)

使用`颜色标记法`剖析树在中序遍历下的递归操作, 思路如下:

1. 将访问过的元素标记为灰色, 未访问过的元素标记为白色;
2. 从栈顶取出访问元素:
   1. 若为灰色元素, 则打印之;
   2. 若为白色元素, 按照`中 -> 右 -> 左`的顺序推入栈, 同时将白色元素标记为灰色元素;

> 推荐使用颜色标记法, 它的解题思路适用于解前序、中序、后序遍历。

```js
     1
    / \
   2   5
  / \
 3   4
```

在如上所示树中, 模拟系统栈图解其执行过程如下:

```js
gray  1
white 2
white 5

white 2
white 5

gray  2
white 3
white 4
white 5
```

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
 * @return {number[]}
 */
var postorderTraversal = function(root) {
  const printArr = []
  if (!root) return printArr
  const stack = []
  stack.push({ color: 'white', node: root })

  while (stack.length > 0) {
    const { color, node } = stack.pop()
    if (color === 'gray') {
      printArr.push(node.val)
    } else {
      stack.push({ color: 'gray', node })
      node.right && stack.push({ color: 'white', node: node.right })
      node.left && stack.push({ color: 'white', node: node.left })
    }
  }

  return printArr
}
```

### Sister Title

94、144

> 为确保内容的实时、准确性, 可以查看[JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/LeetCode/README.md)