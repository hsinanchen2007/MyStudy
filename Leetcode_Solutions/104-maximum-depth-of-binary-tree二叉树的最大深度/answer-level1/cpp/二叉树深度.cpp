### 解题思路
尽量用max函数，比较靠谱

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
        int depth = 0;
        if(root != nullptr)
        return max(maxDepth(root->left),maxDepth(root->right))+1;
        else
         return 0;
    }
};
```