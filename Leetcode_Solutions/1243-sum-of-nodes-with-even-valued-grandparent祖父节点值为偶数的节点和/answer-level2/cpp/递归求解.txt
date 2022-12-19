```
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        dfs(ans, root);
        return ans;
    }

    void dfs(int& ans, TreeNode* root)
    {
    	if(!root) return;
    	if(root->val%2 == 0)
    	{
    		if(root->left)
    		{
    			if(root->left->left)
    				ans += root->left->left->val;
    			if(root->left->right)
    				ans += root->left->right->val;
    		}
    		if(root->right)
    		{
    			if(root->right->left)
    				ans += root->right->left->val;
    			if(root->right->right)
    				ans += root->right->right->val;
    		}
    	}
    	dfs(ans, root->left);
    	dfs(ans, root->right);
    }
};

```
