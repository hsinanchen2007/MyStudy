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
    int maxPathSum(TreeNode* root) {
        if (nullptr == root)
        {
            return 0;
        }

        int res = INT_MIN;

        maxPathSum(root, res);

        return res;
    }

private:
    int maxPathSum(TreeNode* root, int& res)
    {
        if (nullptr == root)
        {
            return 0;
        }

        int left = max(0, maxPathSum(root->left, res));
        int right = max(0, maxPathSum(root->right, res));

        int sum = left + right + root->val;
        res = max(sum, res);
        
        return max(left, right) + root->val;
    }
};
```