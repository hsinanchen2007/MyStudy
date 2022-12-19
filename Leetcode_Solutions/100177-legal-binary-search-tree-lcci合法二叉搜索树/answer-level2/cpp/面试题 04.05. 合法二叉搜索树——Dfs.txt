二叉搜索树满足中序遍历为有序序列的性质，所以直接中序遍历判断是否有序即可。
```
class Solution {
    private:
    bool flag;
    long val;
    void Dfs(TreeNode* root){
        if(root==nullptr||!flag){
            return;
        }
        Dfs(root->left);
        if(root->val>val){
            val=root->val;
        }else{
            flag=false;
            return;
        }
        Dfs(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        flag=true;
        val=LONG_MIN;
        Dfs(root);
        return flag;
    }
};
```
