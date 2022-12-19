### 解题思路
在1 2 这个测试用例卡壳了一下
递归也简单也难，细节还是要好好把握

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
    int minDepth(TreeNode* root) {
        
        if(!root) return 0;
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        return (l&&r)?1+min(l,r):1+l+r;
    }
};
```