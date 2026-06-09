### 解题思路
递归思路：fn(x) = max(fn(x.left),fn(x.right))+1

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
const diameterOfBinaryTree = (root)=> {
  let res = 0;
  const depth = (node)=>{
    if(!node) return 0;
    const L = depth(node.left);
    const R = depth(node.right)
    const dep = Math.max(L, R) + 1;
    res = (L+R+1>res) ? L+R+1 : res;
    return dep;
  }
  depth(root);
  return res > 1 ? res - 1 : 0;
};
```