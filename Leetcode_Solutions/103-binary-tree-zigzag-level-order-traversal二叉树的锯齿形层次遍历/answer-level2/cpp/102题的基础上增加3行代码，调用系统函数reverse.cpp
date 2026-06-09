class Solution {
    vector<vector<int>> result;
public:
    void nextLevel(TreeNode* root, int level) {
        if (root == nullptr) {
            return;
        }

        result.resize(max(level+1, (int)result.size()));
        result[level].push_back(root->val);

        nextLevel(root->left, level+1);
        nextLevel(root->right, level+1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        nextLevel(root, 0);
        
        for (auto i = 0; i < result.size(); i++) {
            if (i & 1) {
                //反转奇数行
                reverse(result[i].begin(), result[i].end());
            }
        }
        
        return result;
    }
};