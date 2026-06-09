1. 二叉树第 n+1 层比第 n 层与根的距离多 1，契合广度优先搜索。
2. 队列中每次保存二叉树一层的节点指针。
3. 开始遍历本层时，记录本层节点数，作为本层遍历完毕的条件。
4. 把出队列的值先存入一层的 vector<int> level。
5. 一层遍历结束后，把level存入最后结果。
```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (!root) return ans;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(move(level));
        }
        return ans;
    }    
};
```
