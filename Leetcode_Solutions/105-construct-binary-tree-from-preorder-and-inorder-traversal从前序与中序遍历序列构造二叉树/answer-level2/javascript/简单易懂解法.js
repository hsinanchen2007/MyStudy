### 解题思路
## 思路
preorder[0] 为根节点 root
inorder 中 preorder 左边为左子树 [9] 右边为右子树 [15, 20, 7]

递归
左子树递归 preorder [9] inorder [9]
return
右子树递归 preorder [20, 15, 7] inorder [15, 20, 7]
  递归
  左子树 preorder [15] inorder[15]
  return
  右子树 preorder [7]  inorder[7]
  return

## 测试用例
[3,9,20,15,7]
[9,3,15,20,7]
[9]
[9]
[3,4,5,6,7,8,9]
[6,5,4,3,7,8,9]

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
 * 
 * @param {any} val 
 */
function TreeNode(val) {
  this.val = val;
  this.left = this.right = null;
}
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    // [] [] 的坑
    if (preorder.length === 0)
      return null;
    let root = new TreeNode(preorder.shift());
    // console.log(root);
    // console.log(inorder);
    // console.log(preorder);
    if (inorder.length === 1) {
      return root;
    }
    let rootf = true;
    let lt = [];
    let rt = [];
    /**
     * 切割
     */
    for(let i = 0; i < inorder.length; i ++) {
      
      if (inorder[i] === root.val) { 
        rootf = false;
        continue;
      }      
      if (rootf) {
        lt.push(inorder[i]);
      } else  {
        rt.push(inorder[i]);
      }
    }

    root.left = lt.length > 0 ? buildTree(preorder, lt) : null;
    root.right = rt.length > 0 ? buildTree(preorder, rt) : null;

    return root;
};
```

