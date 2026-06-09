# 思路
二叉搜索树的特点，左节点小于根节点，右节点大于根节点。如果`root.val`比`val`大，遍历左节点，比`val`小，遍历右节点。`root`为空返回`null`
# 代码
```
public class Solution {
    public TreeNode SearchBST(TreeNode root, int val) {
        if(root==null)return null;

        if(root.val==val)return root;

        if(root.val>val)return SearchBST(root.left,val);
        else return SearchBST(root.right,val);
    }
}
```
