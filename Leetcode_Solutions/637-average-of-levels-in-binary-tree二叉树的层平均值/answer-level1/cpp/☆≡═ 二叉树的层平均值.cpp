1. 层次遍历二叉树，对二叉树每层求和，并计数，然后求平均值。
2. 使用 long long 求和快于使用 double 求和。
```
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return vector<double>();
        queue<TreeNode*> current, next;
        vector<double> ans;
        current.push(root);
        while (!current.empty()) {
            long long sum = 0;
            int cnt = 0;
            while (!current.empty()) {
                TreeNode* node = current.front();
                current.pop();
                sum += node->val;
                ++cnt;
                if (node->left) next.push(node->left);
                if (node->right) next.push(node->right);
            }
            ans.push_back(static_cast<double>(sum) / cnt);
            swap(current, next);
        }
        return ans;
    }
};
```
