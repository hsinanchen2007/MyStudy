![image.png](https://pic.leetcode-cn.com/ade685d1ea2b9a8fb12c4671ad9bc556e52c5e34574f55c4823414f0c020f963-image.png)

### 解题思路
```js
  层次遍历二叉树，每个节点都保留着自己的父节点和祖父节点的值，如果祖父节点值为偶数，
  那么统计此节点的值
  
  队列中的每个元素结构[祖父节点的值，父节点的值，当前节点]
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
 * @param {TreeNode} root
 * @return {number}
 */

var sumEvenGrandparent = function(root) {
  let queue = [], count = 0;
  
  queue.push([null, null, root]);
  
  while (queue.length > 0) {
    let size = queue.length;
    while (size > 0) {
      size--;
      let [grandFather, father, node] = queue.shift();
      
      if (node === null) continue;
      
      if (grandFather !== null && grandFather % 2 === 0) {
        count += node.val;
      }
      
      if (node.left) {
        queue.push([father, node.val, node.left]);
      }
      
      if (node.right) {
        queue.push([father, node.val, node.right]);
      }
    }
  }
  
  return count;
};
```