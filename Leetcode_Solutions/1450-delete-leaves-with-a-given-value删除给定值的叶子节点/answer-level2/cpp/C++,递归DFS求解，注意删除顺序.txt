一定要注意删除的顺序，是将叶子结点是target的结点删除，非叶子结点不是target是不用删除的，eg:1,2,3
所以是先删除左子树结点，再删除右子树结点，知道左右子树均删除完成，则删除完毕！！！
所以删除顺序不能出错！！！
```
class Solution {
public:
    TreeNode* dfs(TreeNode* root,int target){
        if(root==NULL)return NULL;
        //if(!root->left&&!root->right&&root->val==target)return NULL;
        root->left=dfs(root->left,target);
        //if(!root->left&&!root->right&&root->val==target)return NULL;
        root->right=dfs(root->right,target);
        if(!root->left&&!root->right&&root->val==target)return NULL;
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root,target);
    }
};
```
