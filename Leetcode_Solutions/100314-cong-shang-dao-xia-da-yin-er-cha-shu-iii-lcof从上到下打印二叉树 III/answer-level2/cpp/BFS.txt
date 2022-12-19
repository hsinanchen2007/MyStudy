```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        
        queue<TreeNode*> que;
        que.push(root);
        int cnt = 0;        //使用cnt来记录层数
        while(!que.empty()) {
            cnt++;
            int levelSize = que.size();
            vector<int> row;
            for(int i = 0; i < levelSize; i++) {
                TreeNode* cur = que.front(); que.pop();
                row.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            if(cnt % 2 == 0) reverse(row.begin(), row.end());  //若当前层为偶数，则翻转行向量
            res.push_back(row);
        }
        return res;
    }
};
```
