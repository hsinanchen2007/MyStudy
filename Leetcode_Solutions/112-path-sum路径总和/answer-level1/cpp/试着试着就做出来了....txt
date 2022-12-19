### 解题思路


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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        int count = 0;
        return isTrue(root, count, sum);
    }
    bool isTrue(TreeNode* root, int count, int sum)
    {
        count += root->val;
        if (root->left == NULL && root->right == NULL)
        {
            if (count == sum)
                return true;
            return false;
        }
        else
        {
            if (root->left != NULL)
                if (isTrue(root->left, count, sum))
                    return true;
            if (root->right != NULL)
                return isTrue(root->right, count, sum);
        }
        return false;
    }
};
```