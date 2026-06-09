```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            vector<int> row;
            int levelSize = que.size();    //使用levelSize来记录当前队列的大小（每一层）
            for(int i = 0; i < levelSize; i++) {
                TreeNode* cur = que.front(); que.pop();
                row.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            res.push_back(row);
        }
        
        return res;
    }
};
```
