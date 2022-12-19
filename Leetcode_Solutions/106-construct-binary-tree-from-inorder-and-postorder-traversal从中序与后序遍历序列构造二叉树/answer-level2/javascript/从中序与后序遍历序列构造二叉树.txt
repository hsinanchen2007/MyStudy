思路： 例如给定数组中序[9,3,15,20,7]，后序[9,15,7,20,3]， 
    1. 后序遍历最后一个3肯定是根节点。
    2. 在中序遍历中找到根节点，3左边的它的左子树前序遍历，右边是右子树前序遍历
    3. 如果左子树或右子树只有一个节点，那就是它的左节点或者右节点    
    4. 根据 根节点 在前序遍历中的位置，也就是左节点的个数的总数，可以将后序遍历分成 左子树的后序遍历，右子树的后序遍历 
    4. 递归构建子树
```
var buildTree = function(inorder, postorder) {
  if (inorder.length === 0 || !inorder) return null;

  var r = postorder.pop();
  var root = new TreeNode(r);

  var ii = inorder.indexOf(r);

  var il = inorder.slice(0, ii);
  var ir = inorder.slice(ii + 1);

  if (il.length === 1) {
    root.left = new TreeNode(il[0]);
  } else {
    var pl = postorder.slice(0, ii);
    root.left = buildTree(il, pl);
  }

  if (ir.length === 1) {
    root.right = new TreeNode(ir[0]);
  } else {
    var pr = postorder.slice(ii);
    root.right = buildTree(ir, pr);
  }

  return root;
};

```

