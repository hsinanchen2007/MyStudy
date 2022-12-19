
思路：根据二叉搜索树的性质，左子树上结点的值均小于根结点的值，右子树上结点的值均大于根结点的值，左右子树又分别是一棵二叉搜索树。当前结点值和目标结点值比较的情况：
1. 如果当前结点的值等于目标的值直接返回结点；
2. 如果当前结点值小于目标结点值，则在右子树中搜索；
3. 如果当前结点值大于目标结点值，则在左子树中搜索。


**递归**

```
class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if(root == null || root.val == val)return root;
        return root.val>val?searchBST(root.left,val):searchBST(root.right,val);
    }
}
```

**迭代**

```
class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if(root == null)return null;
        while(root != null){
            if(root.val == val)return root;
            root = root.val>val?root.left:root.right;
        }
        return null;
    }
}
```
