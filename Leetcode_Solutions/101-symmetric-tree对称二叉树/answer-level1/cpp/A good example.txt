### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了92.59%的用户
内存消耗 :12.3 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return isSame(root->left, root->right);
    }

    bool isSame(TreeNode* n1, TreeNode* n2){
        if (!n1 && !n2)
            return true;
            
        if (!n1 || !n2)
            return false;
            
        if (n1->val != n2->val)
            return false;
            
        return isSame(n1->left, n2->right) && isSame(n1->right, n2->left);
    }
};
```