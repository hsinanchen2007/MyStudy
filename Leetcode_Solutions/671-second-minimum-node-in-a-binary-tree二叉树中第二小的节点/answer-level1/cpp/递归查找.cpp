```
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {   
        if(root == NULL)
        {
            return -1;
        }
        return find(root, root->val);
    }
    int find(TreeNode* root, int val)
    {
        if(root == NULL)
        {
            return -1;
        }
        if(root->val > val)
        {
            return root->val;
        }
        int left = find(root->left, val);
        int right = find(root->right, val);
        if(left > 0 && right > 0)
        {
            return min(left, right);
        }
        else if(left > 0)
        {
            return left;
        }
        else if(right > 0)
        {
            return right;
        }
        else
        {
            return -1;
        }
    }
};
```
