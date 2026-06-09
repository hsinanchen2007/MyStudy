要注意[1,2]这个测试用例，如果左右子树返回有0的，说明不存在该子树，所以要用存在的子树。
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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left=minDepth(root->left), right=minDepth(root->right);
        return (left && right)?1+min(left,right):1+max(left,right);
    }
};
```
