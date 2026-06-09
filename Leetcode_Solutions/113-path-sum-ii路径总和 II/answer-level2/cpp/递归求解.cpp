```
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<vector<int>> ret;
        if(root == NULL)
        {
            return ret;
        }
        if(sum == root->val)
        {
            if(root->left == NULL && root->right == NULL)
            {
                ret.push_back({root->val});
                return ret;
            }
        }
        if(root->left != NULL)
        {
            res = pathSum(root->left, sum-root->val);
            for(auto r:res)
            {
                r.insert(r.begin(), root->val);
                ret.push_back(r);
            }
        }
        if(root->right != NULL)
        {
            res = pathSum(root->right, sum-root->val);
            for(auto r:res)
            {
                r.insert(r.begin(), root->val);
                ret.push_back(r);
            }
        }
        return ret;
    }
};
```
