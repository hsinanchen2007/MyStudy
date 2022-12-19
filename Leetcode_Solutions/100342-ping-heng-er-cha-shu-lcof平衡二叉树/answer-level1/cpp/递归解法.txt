### 解题思路
这个题目关键是用左右子树深度更高的作为递归返回值，想到这一点就没什么难度了

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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        bool b = true;
        helper(root, b);

        return b;
    }

    int helper(TreeNode* root, bool& b) {
        if (root == nullptr) {
            return 0;
        } 
        int left = helper(root->left, b);
        int right = helper(root->right, b);
        if (b) {
            if (abs(left-right) > 1) {
                b = false;
            }
        }
        return  left > right ? ++left : ++right;    
    }
};
```