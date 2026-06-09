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
    int findSecondMinimumValue(TreeNode* root) {
        return DFS(root, root->val);
    }

private:
    int DFS(TreeNode* root, int min)
    {
        if (nullptr == root)
        {
            return -1;
        }

        if (root->val > min)
        {
            return root->val;
        }

        int left = DFS(root->left, min);
        int right = DFS(root->right, min);

        if (-1 == left)
        {
            return right;
        }

        if (-1 == right)
        {
            return left;
        }
        
        return left < right ? left : right;
    }
};
```