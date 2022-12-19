### 解题思路
与从上到下打印二叉树II相似，不过需要设置一个flag标记，标记是否将v反转即可，用reverse()反转函数。

### 代码

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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode* > q;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            vector<int> v;
            int len = q.size();
            for (int i=0; i<len; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                v.push_back(t->val);
            }
            if (flag) {
                reverse(v.begin(), v.end());
            }
            res.push_back(v);
            flag = !flag;
        }
        return res;
    }
};
```