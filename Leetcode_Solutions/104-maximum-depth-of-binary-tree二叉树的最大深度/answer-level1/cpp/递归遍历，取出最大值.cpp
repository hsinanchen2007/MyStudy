### 解题思路
两个关键点：1.当前节点存在左子节点或右子节点，则深度+1；
2.定义一个成员变量，取出每个遍历的深度中最大值。

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
    int maxCount = 1;
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        getDepth(root, 1);
        return maxCount;
    }
    void getDepth(TreeNode* root, int count)
    {
        if (root->left != NULL || root->right != NULL)
        {
            count++;
            if (count > maxCount)
            {
                maxCount = count;
            }
            if (root->left != NULL)
                getDepth(root->left, count);
            if (root->right != NULL)
                getDepth(root->right, count);
        }
    }
};
```