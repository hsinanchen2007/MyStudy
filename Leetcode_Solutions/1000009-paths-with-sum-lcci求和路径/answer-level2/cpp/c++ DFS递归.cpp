```
class Solution {
public:
    int res=0;
    int pathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        dfs(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return res;
    }

    void dfs(TreeNode* root,int sum)
    {
        int cursum=0;
        if(!root)return;
        cursum+=root->val;
        if(cursum==sum) res++;
        dfs(root->left,sum-cursum);
        dfs(root->right,sum-cursum);
    }
};


```
