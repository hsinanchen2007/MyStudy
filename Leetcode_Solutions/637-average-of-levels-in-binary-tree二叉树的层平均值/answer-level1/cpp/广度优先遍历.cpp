```
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> res;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            double sum = 0;                     // 每层所有节点数值之和
            int i32NodeCount = que.size();      // 每层的节点数
            for (int i = 0; i < i32NodeCount; i++)
            {
                root = que.front();
                sum += root->val;
                que.pop();
                if (root->left)
                    que.push(root->left);
                if (root->right)
                    que.push(root->right);
            }
            res.push_back(sum / i32NodeCount);
        }
        return res;
    }
};
```
