 ** 递归**
 刚开始会走入一个误区，觉得很简单，让右节点值>中间结点值>左节点值就ok，然而二叉搜索树没那么简单，需要右子树所有节点>根节点>左子树所有节点。
** 思路：**为每个节点设一个上届h和下届l，即该节点的值val应该l<val<h，并在递归过程中更新h,l，因此能够想到设递归函数为bool isv(TreeNode* root,TreeNode* low,TreeNode* high);对于根节点，其对应的low,high设为NULL(不用纠结——跟节点的值不是应该大于左节点，小于右节点吗？，因为在进入其左右节点的时候，会将其与root进行比较的)
 1.首先判断root==NULL return true;
 2.判断该节点是否符合low->val<root->val<high<val。
 3.接着递归判断其左右子节点是否符合条件。
   右节点，其下届更新为root,上届为high。
   左节点，其下届为low,上届更新为root。
 4.以上条件都满足，返回true。
 ```
class Solution {
    bool isV(TreeNode* root,TreeNode* low,TreeNode* high){
        if(root==NULL) return true;
        bool b1=true;
        bool b2=true;
        if(low) b1=root->val>low->val?true:false;
        if(high) b2=root->val<high->val?true:false;
        bool b3=isV(root->right,root,high);
        bool b4=isV(root->left,low,root);
        return b1&&b2&&b3&&b4; 
    }
public:
    bool isValidBST(TreeNode* root) {
        return isV(root,NULL,NULL);
    }
};
```
