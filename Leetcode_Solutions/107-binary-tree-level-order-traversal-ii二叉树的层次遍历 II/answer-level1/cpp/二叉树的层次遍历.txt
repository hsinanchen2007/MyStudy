### 解题思路
在层次遍历的时候 将数组插入第一个位置。

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> level;
        queue<TreeNode*> current;
        queue<TreeNode*> next;
        if (root != NULL) current.push(root);
        while(!current.empty()) {
            while(!current.empty()) {
                TreeNode* tmp = current.front();
                current.pop();
                level.push_back(tmp->val);
                if (tmp->left != NULL) {
                    next.push(tmp->left);
                }
                if (tmp->right != NULL) {
                    next.push(tmp->right);
                }
            }
            result.insert(result.begin(), level);
            level.clear();
            swap(next, current);
        }
        return result;  
    }
};
```