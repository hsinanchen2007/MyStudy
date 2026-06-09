```
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
var zigzagLevelOrder = function(root) {
  if (!root) {
      return [];
  }
  const arr = [];
  const queue = [root];
  let layer = 0;
  let length = 1;
  while (queue.length > 0) {
      const curarr = [];
      let currLength = 0;
      for (let i = 0; i < length; i++) {
          const node = queue.shift();
          if (layer % 2 === 0) {
              curarr.push(node.val);
          } else {
              curarr.unshift(node.val);
          }
          if (node.left) {
              queue.push(node.left);
              currLength++;
          }
          if (node.right) {
              queue.push(node.right);
              currLength++;
          }
      }
      layer++;
      length = currLength;
      arr.push(curarr);
  }
  return arr;
};
```

基本思路，和普通的层次遍历是一个道理，都是使用了队列。
1. 单数层 使用push方法**正向**把value放入当前层的数组
2. 偶数层 使用unshift方法**反向**把value放入当前层的数组
