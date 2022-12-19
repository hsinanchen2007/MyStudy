### 解题思路
纯C++ 广度优先

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
        if (nullptr == root)
        {
            return {};
        }

        vector<vector<int>> res;
        vector<TreeNode*> curr;
        vector<TreeNode*> next;

        curr.push_back(root);

        while (false == curr.empty())
        {
            res.push_back({});

            for (auto node : curr)
            {
                res.back().push_back(node->val);

                if (node->left)
                {
                    next.push_back(node->left);
                }

                if (node->right)
                {
                    next.push_back(node->right);
                }
            }

            curr.swap(next);
            next.clear();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
```