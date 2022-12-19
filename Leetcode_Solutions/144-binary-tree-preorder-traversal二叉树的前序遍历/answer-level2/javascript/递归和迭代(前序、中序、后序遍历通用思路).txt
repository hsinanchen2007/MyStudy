### 递归法

首先给出递归解法, 代码很简洁。

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
var preorderTraversal = function(root) {
  if (root) {
    return [root.val, ...preorderTraversal(root.left), ...preorderTraversal(root.right)]
  } else {
    return []
  }
}
```

### 扩展 —— 递归和栈的关系

```js
     1
    / \
   2   5
  / \
 3   4
```

针对如图剖析树在先序遍历下的递归操作, 其执行过程如下:

* 步骤一: 将根节点 1 推入栈;
* 步骤二: 从栈中取出顶部元素 1 并打印。
  * 由于存在右节点 5, 将其推入栈中;
  * 由于存在左节点 2, 将其推入栈中;
* 步骤三: 从栈中取出顶部元素 2 并打印。
  * 由于存在右节点 4, 将其推入栈中;
  * 由于存在左节点 3, 将其推入栈中;
* 步骤四: 从栈中取出顶部元素 3 并打印。
* 步骤五: 从栈中取出顶部元素 4 并打印。
* 步骤六: 从栈中取出顶部元素 5 并打印。

模拟系统栈实现图解:

```js
步骤一:
1

步骤二: 取出 1 并打印;
2
5

步骤三: 取出 2 并打印;
3
4
5

步骤四: 取出 3 并打印;
步骤四: 取出 4 并打印;
步骤四: 取出 5 并打印;
```

代码实现:

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
var preorderTraversal = function(root) {
  const printArr = []
  const stack = []
  if (!root) return []
  stack.push(root)
  while (stack.length > 0) {
    const popValue = stack.pop()
    printArr.push(popValue.val)
    popValue.right && stack.push(popValue.right)
    popValue.left && stack.push(popValue.left)
  }
  return printArr
}
```

### 颜色标记法(迭代法, 模拟系统栈)

使用`颜色标记法`剖析树在中序遍历下的递归操作, 思路如下:

1. 将访问过的元素标记为灰色, 未访问过的元素标记为白色;
2. 从栈顶取出访问元素:
   1. 若为灰色元素, 则打印之;
   2. 若为白色元素, 按照`右 -> 左 -> 中`的顺序推入栈, 同时将白色元素标记为灰色元素;

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
var preorderTraversal = function(root) {
  const printArr = []
  if (!root) return printArr
  const stack = []
  stack.push({
    color: 'white',
    node: root
  })

  while (stack.length > 0) {
    const pickValue = stack.pop()
    const { color, node } = pickValue
    if (color === 'gray') {
      printArr.push(node.val)
    } else {
      node.right && stack.push({ color: 'white', node: node.right })
      node.left && stack.push({ color: 'white', node: node.left })
      stack.push({ color: 'gray', node })
    }
  }

  return printArr
}
```

### Sister Title

144、94、145

> 为确保内容的实时、准确性, 可以查看[JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/LeetCode/README.md)