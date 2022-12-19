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
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int min_num = INT_MAX;
        TreeNode* pre = NULL;
        InOrder(root, pre, min_num);
        return min_num;
    }
    //pre 是引用，否则会出问题
    void InOrder(TreeNode* root, TreeNode*& pre, int& min_num) {
        if (root == NULL) {
            return ;
        }
        
        InOrder(root->left, pre, min_num);
        if (pre != NULL && root->val - pre->val < min_num) {
            min_num = root->val - pre->val;
        }
        pre = root;
        InOrder(root->right, pre, min_num);
    }
};
```