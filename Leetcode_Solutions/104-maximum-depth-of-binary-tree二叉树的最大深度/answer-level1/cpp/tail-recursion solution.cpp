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

// Normal recursion
// 8ms, 19.4MB
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(!root){
//             return 0;
//         }
//         else{
//             return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//         }
//     }
// };


// Tail-Recursion, avoid using too much memory
// 8ms, 19.1MB
class Solution {
public:
    int depth = 0;
        
    void findDepth(TreeNode* root, int level){
        if(!root){
            depth = max(level, depth);
        }
        else{
            findDepth(root->left, level+1);
            findDepth(root->right, level+1);
        }
    }
    
    int maxDepth(TreeNode* root) {
        findDepth(root, 0);
        
        return depth;
    }
};
```