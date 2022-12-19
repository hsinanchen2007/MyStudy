![image.png](https://pic.leetcode-cn.com/ef600ced94566aa2435d256fab63e7d91d90cf620c5328c361ce37b2b3467f0c-image.png)

### 解题思路
```js
  前序遍历顺序：根 -> 左 -> 右
  分析情况：
  节点的左右子树都为 null，直接拼上当前节点值即可
  右子树为 null 括号可以省略，左子树为 null 括号不可省略
```

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
 * @param {TreeNode} t
 * @return {string}
 */

var tree2str = function(t) {
  function ergodic(node) {
    if (node === null) return '';
    if (node.left === null && node.right === null) return `${ans}${node.val}`;
    if (node.right === null) return `${ans}${node.val}(${ergodic(node.left)})`;
    return `${ans}${node.val}(${ergodic(node.left)})(${ergodic(node.right)})`
  }
  
  let ans = '';
  
  return ergodic(t);
};
```