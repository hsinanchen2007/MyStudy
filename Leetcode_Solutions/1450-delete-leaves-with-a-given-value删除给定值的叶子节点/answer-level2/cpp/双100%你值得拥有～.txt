### 解题思路
后续遍历拥有双100%，you deserve it～

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
    void postOrder(TreeNode*& root,int target)
    {
        if(root)
        {
            postOrder(root->left,target);
            postOrder(root->right,target);
            if(root->left==NULL&&root->right==NULL&&root->val==target)
                root=NULL;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        postOrder(root,target);
        return root;
    }
};
```