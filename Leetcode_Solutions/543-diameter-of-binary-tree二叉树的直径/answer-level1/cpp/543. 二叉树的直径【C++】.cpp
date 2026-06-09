### 解题思路

首先这个题需要注意一点，整棵树的最长路径，不一定是左右子树的深度相加，因为可能最长路径并没有经过根结点。但是可以确定的是，最长路径一定是某一个结点作为根节点的左右子树的深度相加。

所以如果求出每一个结点作为根结点的左右子树的深度，也就可以找出所有可能的最长路径，只需要不断更新最大长度即可。

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
    int maxLength = 0;//最大长度

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        getDepth(root);
        return maxLength;
    }

    //获取深度
    int getDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftDepth = getDepth(root->left);//左子树深度
        int rightDepth = getDepth(root->right);//右子树深度
        maxLength = max(maxLength, leftDepth + rightDepth);
        return max(leftDepth, rightDepth) + 1;
    }
};
```