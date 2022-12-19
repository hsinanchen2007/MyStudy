### 解题思路
递归

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
    bool isBalanced(TreeNode* root) {
        if (NULL == root)
        {
            return true;
        }

        bool balanced = true;

        height(root, &balanced);

        return balanced;
    }

private:
    int height(TreeNode* root, bool* balanced)
    {
        if (NULL == root)
        {
            return 0;
        }

        int left_hight = height(root->left, balanced);
        int right_hight = height(root->right, balanced);

        if (abs(left_hight - right_hight) > 1)
        {
            *balanced = false;
            return -1;
        }

        return max(left_hight, right_hight) + 1;
    }
};
```