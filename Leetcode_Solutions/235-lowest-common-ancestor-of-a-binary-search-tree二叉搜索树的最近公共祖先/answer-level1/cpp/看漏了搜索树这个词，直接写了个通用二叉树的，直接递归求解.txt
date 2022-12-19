```
class Solution {
public:
    bool hasOneNode(TreeNode* root, TreeNode* p)
	{
		if(!root)
			return false;
		if(root == p)
			return true;
		return (hasOneNode(root->left, p)) || (hasOneNode(root->right, p));
	}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(true)
        {
        	if(hasOneNode(root->left, p) && hasOneNode(root->left, q))
        		root = root->left;
        	else if(hasOneNode(root->right, p) && hasOneNode(root->right, q))
        		root = root->right;
            else
                break;
        }
        return root;
    }
};
```
