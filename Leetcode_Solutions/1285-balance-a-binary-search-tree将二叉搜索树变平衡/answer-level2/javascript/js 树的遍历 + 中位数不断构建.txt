![image.png](https://pic.leetcode-cn.com/f0af3277cf04c4b27e530c02b22c91d3ffe976622e58d4237dfd7671cd2f5daf-image.png)

### 解题思路
```js
  思路：
  1.中序遍历二叉搜索树，存到一个数组中，数组是升序的(因为二叉搜索树的特性)
  2.层层构建二叉搜索树，每次以中位数为根节点，这样树就是最趋近平衡的
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

var balanceBST = function(root) {
  function bst(node) {
    if (node === null) return ;
    bst(node.left);
    nodes.push( node.val );
    bst(node.right);
  }
  
  let nodes = [];
  bst(root);
  
  function build(arr) {
    if (arr.length === 0) return null;
    
    let mid = Math.floor(arr.length / 2);
    
    if (arr[mid] === undefined) return ;
    
    const root = new TreeNode( arr[mid] );

    root.left = build(arr.slice(0, mid));
    root.right = build(arr.slice(mid + 1));
    
    return root;
  }
  
  let newNode = build(nodes);
  
  return build(nodes);
};
```