
1、DFS

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
    if(root === null) return 0;
    if ((root.left == null) && (root.right == null)) {
      return 1;
    }
    let min_depth = Infinity;
    if(root.left !== null) {
        min_depth = Math.min(minDepth(root.left),min_depth)
    }
    if(root.right !== null) {
        min_depth = Math.min(minDepth(root.right),min_depth)
    }
    return min_depth + 1;
};
```
2、BFS

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
   if(root === null) return 0;
   let queue = [];
   queue.push(root);
   let count = 1;
   while(queue.length) {
       let len = queue.length;
       while(len--) {
           let node = queue.shift();
           if(node.left) queue.push(node.left);
           if(node.right) queue.push(node.right);
           if(node.left === null && node.right === null) {
               return count;
           }
       }
       count++;
   }
   return count;
};
```