### 解题思路
跟二叉树的最大路径和有点相似
不过maxLen现在存放的是节点的个数
因此最后要减１作为二叉树的直径

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
    
    int getMax(TreeNode* root, int& maxLen) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftLen = getMax(root->left, maxLen);
        int rightLen = getMax(root->right, maxLen);
        
        int ret = 1 + leftLen + rightLen;
        if (ret > maxLen) {
            maxLen = ret;
        }
        return 1 + max(leftLen, rightLen);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }
        int maxLen = INT_MIN;
        getMax(root, maxLen);
        
        return maxLen - 1;
    }
};
```