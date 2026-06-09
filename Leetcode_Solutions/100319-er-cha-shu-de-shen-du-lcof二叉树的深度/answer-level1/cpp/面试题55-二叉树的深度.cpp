### 解题思路
代码很简单，理解递归的思路比较重要。
非空根节点，其深度等于左子树和右子树的深度二者之间较大者+1；
递归到每个小的子树上都满足这个设定。

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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return leftDepth>rightDepth ? (leftDepth+1):(rightDepth+1);
    }
};
```