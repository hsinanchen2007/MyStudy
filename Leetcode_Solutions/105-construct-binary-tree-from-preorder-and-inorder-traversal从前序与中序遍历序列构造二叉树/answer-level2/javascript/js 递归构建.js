![image.png](https://pic.leetcode-cn.com/358ccca5adb4850976efb9ef56b3c31358519cfd034d3fc68d3813626b6e86ae-image.png)

### 解题思路
```js
  每次根据前序遍历的根节点分割中序遍历的左右子树，递归即可

  举例：preorder = [3,9,20,15,7] inorder = [9,3,15,20,7]

  此时的根节点是 3，那么当前的节点值是 3，然后用 3 把 inorder 数组分割成两部分：
  [9] [15,20,7]
  用这两个数组继续递归去分别构建左右子树。。。
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
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */

var buildTree = function(preorder, inorder) {
  if (inorder.length === 0) return null;
  
  let index = inorder.indexOf( preorder[0] );
  let root = new TreeNode( preorder.shift() );
  root.left = buildTree(preorder, inorder.slice(0, index));
  root.right = buildTree(preorder, inorder.slice(index + 1));
  
  return root;
};
```