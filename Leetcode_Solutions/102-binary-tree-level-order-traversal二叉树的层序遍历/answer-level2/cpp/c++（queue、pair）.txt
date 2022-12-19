执行用时 :4 ms, 在所有 cpp 提交中击败了96.55%的用户内存消耗 :13.5 MB, 在所有 cpp 提交中击败了99.20%的用户
```

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        queue<pair<TreeNode*,int>> node;
        TreeNode* temp = root;
        node.push({temp, 0});
        pair<TreeNode*,int> t;
        while(!node.empty())
        {
            t = node.front();
            node.pop();
            if(result.size() < t.second + 1)
            {
                vector<int> layer;
                result.push_back(layer);
                result[t.second].push_back(t.first->val);
            }
            else
                result[t.second].push_back(t.first->val);
            if(t.first->left != NULL)
                node.push({t.first->left, t.second + 1});
            if(t.first->right != NULL)
                node.push({t.first->right, t.second + 1});
        }
        return result;
    }
};
```
