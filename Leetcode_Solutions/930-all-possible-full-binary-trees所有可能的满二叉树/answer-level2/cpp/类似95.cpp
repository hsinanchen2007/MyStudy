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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> result;
        if (N%2 == 0) {
            return result;
        }
        TreeNode* root = new TreeNode(0);
        result.push_back(root);
        unordered_map<int, vector<TreeNode*>> m;
        m[1] = result;
        return help(N,m);
    }
    vector<TreeNode*> help(int n, 
                           unordered_map<int, vector<TreeNode*>>& m) {
        if (m.count(n) != 0) {
            return m[n];
        }
        vector<TreeNode*> cur;
        for (int i=1; i<n; i+=2) {
            vector<TreeNode*> left = help(i,m);
            vector<TreeNode*> right = help(n-1-i, m);
            for (auto l:left) {
                for (auto r:right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    cur.push_back(root);
                }
            }
        }
        m[n] = cur;
        return cur;
    }
};
```
![Screen Shot 2019-12-06 at 9.38.08 AM.png](https://pic.leetcode-cn.com/f14936d80f9a7ac00cb53bc64b7da07b44feafc0ce407113444607fead476246-Screen%20Shot%202019-12-06%20at%209.38.08%20AM.png)
