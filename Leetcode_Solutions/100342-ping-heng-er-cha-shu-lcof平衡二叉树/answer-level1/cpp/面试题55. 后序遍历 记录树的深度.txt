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

 //1. 在后序遍历的过程中记录当前树的深度
class Solution {
private:
    bool isBalancedCore(TreeNode * root, int & height) {
        if (root == NULL) {
            height = 0;
            return true;
        }
        int left, right;
        if (isBalancedCore(root->left, left) 
            && isBalancedCore(root->right, right)) {
            
            height = max(left, right) + 1;
            int diff = left - right;
            if (diff <= 1 && diff >= -1)
                return true;
        }
        return false;
    }

public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalancedCore(root, height);
    }
};




//  //2. 用到上一题maxDepth函数
// class Solution {
// private:
//     int maxDepth(TreeNode * root) {
//         if (root == NULL)
//             return 0;
//         return max(maxDepth(root->left), maxDepth(root->right) )+1;
//      }

// public:
//     bool isBalanced(TreeNode* root) {
//         if (root == NULL)
//             return true;
//         if (isBalanced(root->left) 
//             && isBalanced(root->right)) {
//             int diff = maxDepth(root->left) - maxDepth(root->right);
//             if (diff <= 1 && diff >= -1)
//                 return true;
//         }
//         return false;

//     }
// };
```