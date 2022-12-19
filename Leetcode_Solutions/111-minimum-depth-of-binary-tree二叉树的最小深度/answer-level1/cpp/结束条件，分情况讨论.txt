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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->right==NULL || root->left==NULL){
//例如[1,2]，1是根，2是左子树，最小层数是2，因为右子树为空，则mindepth(root->right)==0,
            return minDepth(root->right)+minDepth(root->left)+1;
        }
        return min(minDepth(root->right),minDepth(root->left))+1;
    }
};
```