### 解题思路
右根左遍历，sum起始值为0，sum = 0 会一直维持到树的最右下边，然后随着右根左的顺序累加。

### 代码
```
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        helper(root,sum);
        return root;
    }
    void helper(TreeNode* root,int& sum){
        if(root){
            if(root->right){
                helper(root->right,sum);
            }
            root->val += sum;
            sum = root->val;
            if(root->left){
                helper(root->left,sum);
            }
        }
    }
};
```