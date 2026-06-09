DST递归即可

代码：
```
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == NULL)
            return 0;
        else {
            int ans = 0;
            if (root->val >= L && root->val <= R)
                ans = root->val;
            return ans + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        }
    }
};
```
