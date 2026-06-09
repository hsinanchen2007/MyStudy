## 方法一：深度优先搜索（dfs）
```
class Solution {
public:
    vector<int> res;
    void dfs(TreeNode* curNode, int level) {
        if(res.size() == level) res.push_back(INT_MIN);
        res[level] = max(res[level], curNode->val);
        if(curNode->left) dfs(curNode->left, level+1);
        if(curNode->right) dfs(curNode->right, level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return res;
        dfs(root, 0);
        return res;
    }
};
```
## 方法二：广度优先搜索（bfs）
```
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int levelSize = q.size();
            int levelMax = INT_MIN;
            for(int i = 0; i < levelSize; i++) {
                TreeNode* curNode = q.front();
                q.pop();
                levelMax = max(curNode->val, levelMax);
                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
            }
            res.push_back(levelMax);
        }
        return res;
    }
};
```
