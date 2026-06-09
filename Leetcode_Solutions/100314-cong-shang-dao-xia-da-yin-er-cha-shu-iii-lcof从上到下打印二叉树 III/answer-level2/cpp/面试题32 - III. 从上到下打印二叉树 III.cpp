```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 1. 同上一题，返回时奇数层reverse
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         if (root == NULL)
//             return res;
//         queue<pair<TreeNode*, int>> q;
//         q.push(make_pair(root, 0));
//         while (!q.empty()) {
//             TreeNode * node = q.front().first;
//             int level = q.front().second;
//             q.pop();
//             if (level == res.size())
//                 res.push_back(vector<int>());
//             res[level].push_back(node->val);
//             if (node->left)
//                 q.push(make_pair(node->left, level+1));
//             if (node->right)
//                 q.push(make_pair(node->right, level+1));
//         }
//         // return res;

//         for (int i = 0; i < res.size(); i++)
//             if (i % 2 == 1)
//                 reverse(res[i].begin(), res[i].end());  // 前面和上一题一样，这里reverse

//         return res;
//     }
// };

// 2. 两个栈
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        stack<pair<TreeNode*, int>> s[2];
        s[0].push(make_pair(root, 0));
        int cur = 0;
        
        while (!s[0].empty() || !s[1].empty()) {
            TreeNode * node = s[cur].top().first;
            int level = s[cur].top().second;
            if (level == res.size())
                res.push_back(vector<int>());
            res[level].push_back(node->val);
            s[cur].pop();
            if (cur == 0) {
                if (node->left)  s[1].push(make_pair(node->left, level+1));
                if (node->right) s[1].push(make_pair(node->right, level+1));
            }
            else {
                if (node->right) s[0].push(make_pair(node->right, level+1));
                if (node->left)  s[0].push(make_pair(node->left, level+1));
            }
            if (s[cur].empty())
                cur = 1 - cur;
                
        }
        return res;
    }
};
```