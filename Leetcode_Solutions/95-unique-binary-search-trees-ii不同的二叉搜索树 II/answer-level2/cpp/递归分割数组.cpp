```
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n<1)
            return {};
        return generate(1,n);
    }
    vector<TreeNode*> generate(int i, int j)
    {
        vector<TreeNode*> res;
        vector<TreeNode*> left;
        vector<TreeNode*> right;
        TreeNode * n = NULL;
        if(i>j)
        {
            res.push_back(NULL);
            return res;
        }
        for(int k=i; k<=j; k++)
        {
            left = generate(i, k-1);
            right = generate(k+1, j);
            for(auto l:left)
            {
                for(auto r:right)
                {
                    n = new TreeNode(k);
                    n->left = l;
                    n->right = r;
                    res.push_back(n);
                }
            }
        }
        return res;
    }
};
```
