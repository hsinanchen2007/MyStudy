```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        TreeNode *cur = root;
        queue <TreeNode *> qu;
        qu.push(cur);
        int count = 1; // count为当前层数剩余的节点数量
        vector <int> temp;
        while (!qu.empty()) {
            while (count) { // 
                TreeNode *node = qu.front();
                qu.pop();
                temp.push_back(node->val);
                count--;
                if (node -> left) {
                    qu.push(node->left);
                }
                if (node -> right) {
                    qu.push(node->right);
                }
            }
            count = qu.size();
            res.push_back(temp);
            temp.clear();   
        }
        return res;
    }
};
```
