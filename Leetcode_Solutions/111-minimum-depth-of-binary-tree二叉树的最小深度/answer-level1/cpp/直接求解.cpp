### 解题思路
求出到每个叶子节点的深度，分别与成员minCount比较。

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
    int minCount = INT_MAX;
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        getDepth(root, 1);
        return minCount;
    }
    void getDepth(TreeNode* root, int count)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (count < minCount)
                minCount = count;
        }
        if (root->left != NULL || root->right != NULL)
        {
            count++;
            if (root->left != NULL)
                getDepth(root->left, count);
            if (root->right != NULL)
                getDepth(root->right, count);
        }
    }
};
```