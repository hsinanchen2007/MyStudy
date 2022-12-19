### 解题思路
执行用时 :8 ms, 在所有 C++ 提交中击败了65.12%的用户内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *left_next = root->left;
        if(left_next == NULL) return;
        while(left_next->right != NULL){
            left_next = left_next->right;
        }
        left_next->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
};
```