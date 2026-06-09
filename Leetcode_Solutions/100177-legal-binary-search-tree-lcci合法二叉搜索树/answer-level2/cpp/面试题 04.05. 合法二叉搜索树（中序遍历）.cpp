二叉搜索树中序遍历是有序的，所以进行中序遍历，每次比较当前结点的值与其前驱结点（如果有的话）的值即可。
用一个变量记录前驱结点，初始为nullptr。
用一个bool变量flag表示是否是BST，如果遍历到某个结点的值小于或等于其前驱结点的值，则修改flag为false,并退出中序遍历。

```
class Solution {
public:
    void InOrder(TreeNode *root,TreeNode*& pre,bool &flag){
        if(!root) return;
        InOrder(root->left,pre,flag);
        if(pre&&root->val<=pre->val) {
            flag=false;
            return;
        }
        pre=root;
        InOrder(root->right,pre,flag);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode *pre=nullptr;
        bool flag=true;
        InOrder(root,pre,flag);
        return flag;
    }
};
```
