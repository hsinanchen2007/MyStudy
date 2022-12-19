```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> rets;
        vector<int> row;
        queue<TreeNode*> que;
        // 按行打印的代码
        int next =0;
        TreeNode *p = root;
        if (root == NULL) return rets;
        que.push(p);
        int cur = 1;
        while (que.size()) {
            TreeNode *tmp = que.front();
            row.push_back(tmp->val);
            que.pop();
            cur--;
            if (tmp->left) {
                next++;
                que.push(tmp->left);
            }
            if (tmp->right) {
                next++;
                que.push(tmp->right);
            }
            if (cur == 0) {
                cur = next;
                next = 0;
                rets.push_back(row);
                row.clear();
            }
        }
        // 首尾进行交换
        int i = 0; 
        int j = rets.size() -1;
        while (i <= j) {
            vector<int> tmp = rets[i];
            rets[i] = rets[j];
            rets[j] = tmp;
            i++;
            j--;
        }
        return rets;

    }
};
```
由此可以显而易见，使用栈的结构来简化数组倒序

```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> rets;
        stack<vector<int>> s;
        vector<int> row;
        queue<TreeNode*> que;
        // 按行打印的代码
        int next =0;
        TreeNode *p = root;
        if (root == NULL) return rets;
        que.push(p);
        int cur = 1;
        while (que.size()) {
            TreeNode *tmp = que.front();
            row.push_back(tmp->val);
            que.pop();
            cur--;
            if (tmp->left) {
                next++;
                que.push(tmp->left);
            }
            if (tmp->right) {
                next++;
                que.push(tmp->right);
            }
            if (cur == 0) {
                cur = next;
                next = 0;
                s.push(row);
                row.clear();
            }
        }
        while (!s.empty()) {
            rets.push_back(s.top());
            s.pop();
        }
        return rets;

    }
```
