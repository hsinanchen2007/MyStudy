为了避免溢出，使用double来存储序号信息
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
    using DT = double;
    map<DT, DT> L;
    map<DT, DT> R;
    void helper(TreeNode* root, DT d, DT x) {
        if (root == NULL) return;
        if (L.count(d) == 0) L[d] = x;
        if (R.count(d) == 0) R[d] = x;
        L[d] = min(L[d], x);
        R[d] = max(R[d], x);
        helper(root->left, d + 1, 2 * x);
        helper(root->right, d + 1, 2 * x + 1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        L.clear();
        R.clear();
        if (root == NULL) return 0;
        helper(root, 0, 0);
        DT res = 0;
        for (auto& p : L) res = max(res, R[p.first] - p.second + 1);
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/6b97ae56675a5baf974c550c7b67459e403ce94b6d5d3b386ae48e37cec361c4-image.png)
