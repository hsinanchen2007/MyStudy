```
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ret1 = getLeafs(root1);
        vector<int> ret2 = getLeafs(root2);
        return ret1 == ret2;
    }
    vector<int> getLeafs(TreeNode* root)
    {
        stack<TreeNode*> stk;
        vector<int> ret;
        while(root != NULL || !stk.empty())
        {
            while(root != NULL)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(root->left == NULL && root->right == NULL)
            {
                ret.push_back(root->val);
            }
            root = root->right;
        }
        return ret;
    }
};
```
