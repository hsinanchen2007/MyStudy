### 解题思路
tree

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
    int ans=1;
public:
    int search(TreeNode* root)
    {
        if(root==NULL) return 0;
        else
        {
            int l=search(root->left);
            int r=search(root->right);
            ans=max(ans,l+r+1);
            return max(l,r)+1;
        }
    }

    int diameterOfBinaryTree(TreeNode* root) {
        search(root);
        return ans-1;
    }
};
```