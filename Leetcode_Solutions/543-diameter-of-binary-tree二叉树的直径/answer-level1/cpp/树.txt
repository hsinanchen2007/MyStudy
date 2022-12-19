### 解题思路
树的问题一般都可以用递归去搜索解决

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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        return max(diameterOfBinaryTree(root->left),max(diameterOfBinaryTree(root->right),getdeep(root->left)+getdeep(root->right)));
    }
    int getdeep(TreeNode* root){
        if(root==NULL) return 0;
        else return max(getdeep(root->left),getdeep(root->right))+1;
    }
};
```