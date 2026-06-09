递归：
- val > V 则进入左子树
- val <= V 则进入右子树

找到结点后，拿出子树后，需要接上断开部分！
- 在左子树则：root->left = result[1];
- 在右子树则：root->right = result[0];

```
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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> result(2, nullptr);
        if(!root) return result;
        if(root->val > V){
            result = splitBST(root->left, V);
            root->left = result[1];
            return {result[0], root};
        }
        result = splitBST(root->right, V);
        root->right = result[0];
        return {root, result[1]};
    }
};
```