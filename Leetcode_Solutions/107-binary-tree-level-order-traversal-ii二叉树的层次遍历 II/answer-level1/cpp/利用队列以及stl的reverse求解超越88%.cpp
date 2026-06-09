遍历每一层，每一层新生成一个vector<int>, 结束再用std::reverse逆反下， 或者也可以用stack<vector<int>> 存第一波结果， 然后再push到答案
```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>{};
        queue<TreeNode *> levelQ;
        vector<vector<int>> res;
        levelQ.push(root);
        while(!levelQ.empty()) {
            int size = levelQ.size();
            vector<int> oneRes;
            while (size != 0) {
                TreeNode* node = levelQ.front();
                levelQ.pop();
                if (node->left != nullptr) levelQ.push(node->left);
                if (node->right != nullptr) levelQ.push(node->right);
                size--;
                oneRes.push_back(node->val);
            }
            res.push_back(oneRes);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
```
