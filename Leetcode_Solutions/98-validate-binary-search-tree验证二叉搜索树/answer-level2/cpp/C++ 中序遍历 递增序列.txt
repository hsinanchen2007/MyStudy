二叉搜索树中序遍历序列为严格递增序列，生成序列过程中逐元素判断是否递增，注意边界条件
```
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        long inorder = LONG_MIN;
        stack<TreeNode *> s;
        while(!s.empty() || root){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(root->val <= inorder) return false;
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};
```
