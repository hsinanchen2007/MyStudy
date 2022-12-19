### 解题思路
思路很简单，利用二叉搜索树的特性，**右边节点比左边节点大**
1. 有右节点，先递归右节点
2. 右节点为空，则把当前节点压栈
3. 再遍历当前压栈节点的左子树
4. 重复1-3，直到栈元素为K

性能不是很好

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthLargest = function(root, k) {
  const stack = [];
  let res = 0;
  function find(node) {
    if (node.right) {
      find(node.right);
    }
    if (stack.length < k) {
      stack.push(node.val);
      if (stack.length === k) {
        res = stack[stack.length - 1];
        return;
      }
    }
    if (node.left && stack.length < k) {
      find(node.left);
    }
  }
  find(root);
  return res;
};
```