都是套路
```
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        std::vector<int> pathall;
        int ret = 0;
        dfs(root, pathall, sum, ret);
        return ret;
    }

    void dfs(TreeNode* root, std::vector<int>& pathall, int sum, int& ret)
    {
        if(not root)
        {
            return;
        }

        for(int& n : pathall)
        {
            n+= root->val;
            if(n == sum)
            {
                ret++;
            }
        }
        pathall.push_back(root->val);
        if (sum == root->val)
        {
            ret++;
        }
       
        dfs(root->left, pathall, sum, ret);
        dfs(root->right, pathall, sum, ret);
        pathall.pop_back();
        for(int& n : pathall)
        {
            n-= root->val;
        }
    }
};
```
