### 解题思路
此处撰写解题思路

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
        vector<vector<int> > res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode*> levels[2];
        int current = 0;
        vector<int> item;
        levels[current].push(root);
        int m_iCurLevel = 1;
        int m_iNextLevel = 0;
        while(!levels[0].empty() || !levels[1].empty()) {
            TreeNode* node = levels[current].top();
            levels[current].pop();
            if (current == 0) {
                if (node->left != NULL) {
                    levels[1-current].push(node->left);
                    ++m_iNextLevel;
                }
                if (node->right != NULL) {
                    levels[1-current].push(node->right);
                    ++m_iNextLevel;
                }
            } else {
                if (node->right != NULL) {
                    levels[1-current].push(node->right);
                    ++m_iNextLevel;
                }
                if (node->left != NULL) {
                    levels[1-current].push(node->left);
                    ++m_iNextLevel;
                }
            }
            item.push_back(node->val);
            --m_iCurLevel;
            if (m_iCurLevel == 0) {
                res.push_back(item);
                current = 1 - current;
                m_iCurLevel = m_iNextLevel;
                m_iNextLevel = 0;
                item.clear();
            }
        }
        return res;
    }
};
```