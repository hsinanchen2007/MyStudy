后序遍历
先不考虑怎么写代码，我们见到这道题首先想到的思路肯定是把当前节点的左子树接到右边去，那么问题
来了，我们是从上往下接还是从下往上接？

当时我第一反应是从下往上接，后面看题解有一老哥的自顶向下接也是秀了我一脸，偷偷把他代码扒过来
好像居然还可以从右边接，果然世界之大无奇不有！

先说下从下往上接的思路，从下往上接意味着我们接的时候左子树已经被拉直了，也就是一棵右斜树，那
么我们就需要把左子树最右边的结点（也就是斜树最右边的结点找到），然后这个节点指向当前根节点的
右子树，然后当前节点的右子树指向该结点，最后返回当前根节点

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        //将左子树连在右节点，并将根节点的右子树与其相连
        solve(root);
    }
    TreeNode* solve(TreeNode *root)
    {
        if(!root)
            return NULL;
        TreeNode *l = solve(root->left);
        TreeNode *curRight = solve(root->right);
        root->left = NULL;//这里千万别忘记，不然。。后果自负
        if(l)//如果左边为空，我们不做任何改变
        {
            TreeNode *tmpLeft = l;//保存当前得到的左结点
            while(l->right)
                l = l->right;
            l->right = curRight;
            root->right = tmpLeft;
        }
        return root;
    }
};
那个老哥的解法
public void flatten(TreeNode root) {
    while (root != null) { 
        //左子树为 null，直接考虑下一个节点
        if (root.left == null) {
            root = root.right;
        } else {
            // 找左子树最右边的节点
            TreeNode pre = root.left;
            while (pre.right != null) {
                pre = pre.right;
            } 
            //将原来的右子树接到左子树的最右边节点
            pre.right = root.right;
            // 将左子树插入到右子树的地方
            root.right = root.left;
            root.left = null;
            // 考虑下一个节点
            root = root.right;
        }
    }
}
