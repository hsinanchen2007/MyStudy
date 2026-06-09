# 递归
```
class Solution {
public:
// DFS
    void traverse(TreeNode* root, int level, vector<vector<int>>& res)
    {
        if (!root) return;

        if (level < res.size())
        {
            res[level].push_back(root->val);
        }
        else
        {
            res.emplace_back(vector<int>(1, root->val));
        }

        traverse(root->left, level + 1, res);
        traverse(root->right, level + 1, res);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        traverse(root, 0, res);

        return res;
    }
};
```

# 迭代
```
class Solution {
public:
// BFS
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> eachLayer;
            int iSize = q.size();

            while(iSize--)
            {
            auto tmp = q.front(); 
            q.pop();
            eachLayer.push_back(tmp->val);
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
            }

            res.emplace_back(eachLayer);
        }

        return res;
    }
}
```