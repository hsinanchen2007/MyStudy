```
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while (!q.empty()) {
            vector<int> list;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* tmp = q.front();
                list.push_back(tmp->val);
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            if (level % 2) {
                reverse(list.begin(), list.end());
            }
            result.push_back(list);
            ++level;
        }
        return result;
    }
};
```
思路很简单，跟102一样，先用队列完成层次遍历，然后只需要加入对Level的判断，如果是偶数层不用反转，奇数层则对该层的list调用reverse进行反转即可。运行时间4ms。