```
![image.png](https://pic.leetcode-cn.com/9bf33f06ee9b15fe2bb230c72c84443793df2ce92e079c05ffd7bf69473ec1f4-image.png)
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
    int nextDepth(TreeNode* root) {
        if(root == NULL) {
            return 1;
        }
        if(root->left == NULL) {
            return nextDepth(root->right) + 1;
        } 
        if(root->right == NULL) {
            return nextDepth(root->left) + 1;
        }
        return  max(nextDepth(root->left), nextDepth(root->right)) + 1;

    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return max(nextDepth(root->left), nextDepth(root->right));
    }
};
```
