递归遍历，按照深度逐渐×10，作为进位。
```
class Solution {
    int dfs(TreeNode *root, int level){
        int val = level*10+root->val;
        int left = root->left?dfs(root->left,val):0;
        int right = root->right?dfs(root->right,val):0;
        return max(left+right,val);
    }
public:
    int sumNumbers(TreeNode* root) {
        return root?dfs(root,0):0;
    }
};
```
