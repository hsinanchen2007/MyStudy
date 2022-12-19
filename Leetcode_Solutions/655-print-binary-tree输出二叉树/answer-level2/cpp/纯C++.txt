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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int widths = (1 << height) - 1;

        vector<vector<string>> res(height, vector<string>(widths, ""));
        fill(root, res, 0, 0, widths - 1);
        return res;
    }

private:
    int getHeight(TreeNode* root)
    {
        if (nullptr == root)
        {
            return 0;
        }

        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    void fill(TreeNode* root, vector<vector<string>>& res, int height, int left, int right)
    {
        if (nullptr != root)
        {
            int mid = left + (right - left) / 2;

            res[height][mid] = std::to_string(root->val);

            fill(root->left, res, height + 1, left, mid - 1);
            fill(root->right, res, height + 1, mid + 1, right);
        }
    }
};
```