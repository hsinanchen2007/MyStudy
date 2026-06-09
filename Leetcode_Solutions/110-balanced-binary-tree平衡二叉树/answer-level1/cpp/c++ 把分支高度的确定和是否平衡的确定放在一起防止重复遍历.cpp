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
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if (root == NULL) return true;
//         if (!isBalanced(root->left) || !isBalanced(root->right)) return false;
//         return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1;
//     }
    
//     int maxDepth(TreeNode* root){
//         if (root == NULL) return 0;
//         return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//     }
// };

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int max_height;
        return dfs(root, max_height);
    }
    
    bool dfs(TreeNode* root, int &max_height){
        if (root == NULL) {
            max_height = 0;
            return true;
        }
        int left_height, right_height;
        bool left = dfs(root->left, left_height), right = dfs(root->right, right_height);
        if(!left || !right) return false;
        if(abs(left_height-right_height) > 1) return false;
        max_height = max(left_height, right_height) + 1;
        return true;
    }
};
```