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
    // 按照排序好的数组重新建树
    TreeNode* buildBST(vector<TreeNode*> &vec, int start, int end) {
        if (start >= end)
            return NULL;
        else {
            auto half = (start + end) / 2;
            auto root = vec[half];
            root->left = buildBST(vec, start, half);
            root->right = buildBST(vec, half + 1, end);
            return root;
        }
    }

    TreeNode* balanceBST(TreeNode* root) {
        queue<TreeNode*> qt;
        if (root)
            qt.push(root);
        vector<TreeNode*> vec;
        // 遍历原来的树，拆下所有的节点，放到vector里面
        while (!qt.empty()) {
            auto p = qt.front();
            qt.pop();
            if (p->left)
                qt.push(p->left);
            if (p->right)
                qt.push(p->right);
            vec.push_back(p);
            p->left = NULL;
            p->right = NULL;
        }
        // 排序vector
        sort(vec.begin(), vec.end(), [](TreeNode *a, TreeNode *b) {
            return a->val < b->val;
        });
        return buildBST(vec, 0, vec.size());
    }
};
```