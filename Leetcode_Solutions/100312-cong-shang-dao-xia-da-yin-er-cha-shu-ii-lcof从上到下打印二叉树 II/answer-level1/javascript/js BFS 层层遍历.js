![image.png](https://pic.leetcode-cn.com/077dffd9914dbb99643f23f9fec5f016579d0e28eab392a3bb338dd09068e18d-image.png)

### 解题思路
```js
BFS 层层遍历二叉树
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
 * @return {number[][]}
 */

var levelOrder = function(root) {
  let ans = [], queue = [];
  
  if (root === null) return ans;
  
  queue.push( root );
  
  while (queue.length > 0) {
    let size = queue.length, temp = [];
    while (size > 0) {
      let offer = queue.shift();
      if (offer === null) continue;
      temp.push( offer.val );
      if (offer.left) queue.push( offer.left );
      if (offer.right) queue.push( offer.right );
      size--;
    }
    ans.push( [...temp] );
    temp = [];
  }
  
  return ans;
};
```