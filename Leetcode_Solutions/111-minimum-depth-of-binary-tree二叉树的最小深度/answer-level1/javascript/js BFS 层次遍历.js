![image.png](https://pic.leetcode-cn.com/1871741b5188735605a3a772f98e2d7075d9d4a9844ce4f6e555cc1ac8bea30d-image.png)

### 解题思路
```js
BFS 遍历二叉树，一旦遇到节点的左右子节点都为 null，那么此时的深度就是最小深度
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

var minDepth = function(root) {
  let deep = 0, queue = [], isEnd = false;
  
  if (root !== null) {
    deep = 1;
    queue.push( root );
  }
  
  while (queue.length > 0 && !isEnd) {
    let size = queue.length;
    while (size > 0) {
      let offer = queue.shift();
      if (!offer.left && !offer.right) {
        isEnd = true;
        break;
      }
      
      if (offer.left) queue.push( offer.left );
      if (offer.right) queue.push( offer.right );
      size--;
    }
    
    if (size === 0) deep += 1;
  }
  
  return deep;
};
```