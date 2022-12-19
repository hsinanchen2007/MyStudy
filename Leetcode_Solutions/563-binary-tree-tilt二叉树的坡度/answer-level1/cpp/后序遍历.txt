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
    // 后序遍历
    int postOrderTraversal(TreeNode* root, int & treeDegree)
    {
        if(root == NULL)
            return 0;
        int left = postOrderTraversal(root->left, treeDegree);
        int right = postOrderTraversal(root->right, treeDegree);
        treeDegree += abs(left - right);
        return root->val + left + right;
    }
    
    int findTilt(TreeNode* root) {
        int treeDegree = 0;
        postOrderTraversal(root, treeDegree);
        return treeDegree;
    }
};
```