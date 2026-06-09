![image.png](https://pic.leetcode-cn.com/b544914b96438aefd759a911b1c414936c98711abaec42d464a05056fe4a8e3a-image.png)

### 解题思路
```js
中序遍历 + 构建新树
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
 * @return {TreeNode}
 */

var increasingBST = function(root) {
  let ans = new TreeNode( null ),
      arr = [],
      curr = ans;
  
  function ergodic(node) {
    if (node === null) return ;
    
    ergodic(node.left);
    arr.push( node.val );
    ergodic(node.right);
  }
  
  ergodic(root);
  
  while (arr.length > 0) {
    curr.right = new TreeNode( arr.shift() );
    curr = curr.right;
  }
  
  return ans.right;
};
```