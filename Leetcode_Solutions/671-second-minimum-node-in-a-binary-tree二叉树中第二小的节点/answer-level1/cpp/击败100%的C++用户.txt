```
class Solution {
public:
    void access(TreeNode* root, int& first, int& second)
    {
        if(root == NULL) return;
        if(root->val > first && (second == -1 || root->val < second))
        {
            second = root->val;
        }
        access(root->left, first, second);
        access(root->right, first, second);
    }

    int findSecondMinimumValue(TreeNode* root) {
        int first = root->val, second = -1;
        access(root, first, second);
        return second;
    }

};
```