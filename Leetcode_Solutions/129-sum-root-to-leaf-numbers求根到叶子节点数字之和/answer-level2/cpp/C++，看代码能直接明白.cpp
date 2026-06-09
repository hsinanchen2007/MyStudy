### 解题思路
此处撰写解题思路

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int sum = 0;

    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return sum;
    }

    void helper(TreeNode* root, int tmp){
        if(!root) return;

        tmp += root->val;

        if(!root -> left && !root->right){
            sum += tmp;
            return;
        }
        
        helper(root->left, tmp*10);
        helper(root->right, tmp*10);
    }
};
```