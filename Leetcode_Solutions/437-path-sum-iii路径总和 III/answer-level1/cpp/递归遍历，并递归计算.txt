```
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        if(root == NULL)
            return 0;
        path(root, sum, sum, count, 0);
        return count;
    }
    void path(TreeNode* root, int sum, int target, int& count, int flag)
    {
        if(flag==0)
        {
            path(root, target, target, count, 1);
        }
        else if(sum == root->val)
        {
            count++;
        }
        if(root->left)
            path(root->left, sum-root->val, target, count, flag);
        if(root->right)
            path(root->right, sum-root->val, target, count, flag);
    }
};
```
