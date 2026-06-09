### 解题思路
- 核心要点：二叉树平衡的条件：空树 或 **左右子树高度差小于2且左右子树也是平衡二叉树**
- 执行用时：28 ms, 在所有 C++ 提交中击败了20.69%的用户
- 内存消耗：21.5 MB, 在所有 C++ 提交中击败了100.00%的用户
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
        if(root==NULL)return true;
        return abs(height(root->left)-height(root->right))<2&&isBalanced(root->left)&&isBalanced(root->right);
    }
    int height(TreeNode*root){
        if(root==NULL)return 0;
        return max(height(root->left),height(root->right))+1;
    }
};
```