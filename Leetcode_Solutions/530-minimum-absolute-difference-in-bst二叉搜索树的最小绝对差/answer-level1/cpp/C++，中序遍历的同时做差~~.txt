```
class Solution {
public:
    vector<int> vals;
    int mindif = 9999;
    int getMinimumDifference(TreeNode* root) {
        return savavals(root);
    }
    
    int savavals(TreeNode* root)
    {
        if(!root)
            return mindif;
        if(root -> left)
            getMinimumDifference(root -> left);
        vals.push_back(root -> val);
        if(vals.size() >= 2 && vals[vals.size() - 1] - vals[vals.size() - 2] < mindif)
            mindif = vals[vals.size() - 1] - vals[vals.size() - 2];
        if(root -> right)
            getMinimumDifference(root -> right);
        return mindif;
    }
};
```