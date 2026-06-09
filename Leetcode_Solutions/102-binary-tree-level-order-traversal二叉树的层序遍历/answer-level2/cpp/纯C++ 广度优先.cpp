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
    vector<vector<int>> levelOrder(TreeNode* root) {
        return BFS(root);
    }

private:
    vector<vector<int>> BFS(TreeNode* root)
    {
        if (!root)
        {
            return {};
        }

        vector<vector<int>> ans;
        vector<TreeNode*> curr;
        vector<TreeNode*> next;

        curr.push_back(root);

        while (false == curr.empty())
        {
            ans.push_back({});

            for (TreeNode* node : curr)
            {
                ans.back().push_back(node->val);

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
        return ans;
    }
};
```