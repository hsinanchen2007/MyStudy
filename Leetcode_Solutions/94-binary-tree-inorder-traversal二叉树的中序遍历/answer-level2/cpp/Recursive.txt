algorithm
```
if root == null:
    return {};

else recursive(root)

recursive(root)
{
    // left -> root -> right
    if (root->left) 
       recursive(root->left)
    ans.push_back(root->val)
    else if (root->right)
       recursive(root->right)
}
```


code 
```
class Solution {
public:
    vector<int> ans = {};
    void helper(TreeNode* node)
    {
        if (node->left){
            helper(node->left);
        }
        ans.push_back(node->val);
        if (node->right){
            helper(node->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL){
            return {};
        }
        helper(root);
        return ans;
    }
};
```