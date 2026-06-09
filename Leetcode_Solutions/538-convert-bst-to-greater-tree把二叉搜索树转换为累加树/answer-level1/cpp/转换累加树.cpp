按照右子树-根节点-左子树的情况遍历，定义一个累加和的全局变量，每次到跟节点的时候更新
```
class Solution {
public:
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        root->right=convertBST(root->right);
        root->val+=sum;
        sum=root->val;
        root->left=convertBST(root->left);
        return root;
    }
};
```
