### 解题思路
在层次遍历的基础上稍作调整； 偶数层的时候，在添加数组时，将值插在数组首尾， 这样就是锯齿形遍历。

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> current, next;
        vector<int> level;
        if (root != NULL) current.push(root);
        bool order = true;
        while (!current.empty()) {
            while(!current.empty()) {
                TreeNode* tmp = current.front();
                current.pop();
                if (order) {
                    level.push_back(tmp->val);
                } else {
                    level.insert(level.begin(), tmp->val);
                }
                if (tmp->left != NULL) next.push(tmp->left);
                if (tmp->right != NULL) next.push(tmp->right);  
            }
            order = !order;
            result.push_back(level);
            level.clear();
            swap(next, current);
        }
        return result;
    }
};
```