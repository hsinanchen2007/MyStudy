### 解题思路
纯C++

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
    vector<TreeNode*> generateTrees(int n) {
        if (0 == n) return {};
        return helper(1, n);
    }

private:
    vector<TreeNode*> helper(int min, int max)
    {
        vector<TreeNode*> res;
        if (min > max) res.push_back(nullptr);

        for (int i = min; i <= max; i++)
        {
            vector<TreeNode*> left_vector = helper(min, i - 1);
            vector<TreeNode*> right_vector = helper(i + 1, max);

            for (auto left : left_vector)
            {
                for (auto right : right_vector)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

```