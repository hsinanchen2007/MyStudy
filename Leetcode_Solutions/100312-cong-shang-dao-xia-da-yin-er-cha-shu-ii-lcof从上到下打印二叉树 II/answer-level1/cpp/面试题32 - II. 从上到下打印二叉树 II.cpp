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

 //1. 队列 queue<pair<TreeNode*, int>> q;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode * node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level == res.size())
                res.push_back(vector<int>());
            res[level].push_back(node->val);
            if (node->left)
                q.push(make_pair(node->left, level+1));
            if (node->right)
                q.push(make_pair(node->right, level+1));
        }
        return res;
    }
};

//// 2. 队列  queue<TreeNode*> q;
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         if (root == NULL)
//             return res;     
//         queue<TreeNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             vector<int> sub;
//             int l = q.size();  // 一定要设定这个l 不能放在for循环中，因为q.size()会变
//             for (int i = 0; i < l; i++) {
//                 TreeNode * node = q.front();
//                 sub.push_back(node->val);
//                 q.pop();
//                 if (node->left) 
//                     q.push(node->left);
//                 if (node->right)
//                     q.push(node->right);
//             }
//             res.push_back(sub);
//         }    
//         return res;
//     }
// };


```