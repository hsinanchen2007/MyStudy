BFS，层序遍历，每一层计算一次平均值，并插入答案vector

代码：
```
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        ans.push_back(root->val);
        vector<TreeNode*> node;
        node.push_back(root);
        while (!node.empty()) {
            int num = node.size();
            double sum = 0;
            while (num) {
                if (node[0]->left) {
                    node.push_back(node[0]->left);
                    sum = sum + node[0]->left->val;
                }
                if (node[0]->right) {
                    node.push_back(node[0]->right);
                    sum = sum + node[0]->right->val;
                }
                node.erase(node.begin());
                num--;
            }
            if (node.size())
                ans.push_back(sum / node.size());
        }
        return ans;
    }
};
```
