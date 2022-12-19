## 宽度优先搜索思路

每次扩展路径的时，如果存在左/右节点的话，则累加左/右节点的值，并且记录这个左/右节点后开始扩展。同时在也把左/右节点作为根节点开始扩展。

这里要注意，从左/右节点作为根节点扩展的情况，需要用一个`unordered_map`去记录该节点作为根节点扩展是否已出现过，避免从出现重复的情况。

## 代码：
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
    int ans = 0;
    int pathSum(TreeNode* root, int sum) {
        queue<pair<int, TreeNode*> > Q;
        unordered_map<TreeNode*, bool> book;

        if (root != NULL)
            Q.push(make_pair(root->val, root));

        while (!Q.empty()) {
            pair<int, TreeNode*> cur = Q.front(); Q.pop();
            int value = cur.first;
            TreeNode* node = cur.second;

            if (value == sum) {
                ans++;
            }
            
            if (node->left != NULL) {
                Q.push(make_pair(value + node->left->val, node->left));
                if (!book[node->left]) {
                    Q.push(make_pair(node->left->val, node->left));
                    book[node->left] = true;
                }
            }
            if (node->right != NULL) {
                Q.push(make_pair(value + node->right->val, node->right));
                if (!book[node->right]) {
                    Q.push(make_pair(node->right->val, node->right));
                    book[node->right] = true;
                }
            }
        }

        return ans;
    }
};
```
