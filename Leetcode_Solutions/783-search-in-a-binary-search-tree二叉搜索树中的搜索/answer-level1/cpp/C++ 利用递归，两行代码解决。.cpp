class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //无论当前的root是空还是搜索到目标值，都返回相同的值，为root
        if (root == nullptr || root ->val == val)  return root;
        //进行迭代
        return (root -> val < val) ? searchBST(root -> right, val):searchBST(root -> left, val);
    }
};