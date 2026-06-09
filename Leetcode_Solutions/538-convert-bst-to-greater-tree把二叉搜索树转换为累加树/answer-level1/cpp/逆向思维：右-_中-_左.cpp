```
class Solution {
public:
    int search(TreeNode* root, int sum) {
        if(root == NULL) 
            return sum;
        int right_val = search(root->right, sum);
        root->val += right_val;
        int left_val = search(root->left, root->val);
        return left_val;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        search(root, 0);
        return root;
    }

};
```