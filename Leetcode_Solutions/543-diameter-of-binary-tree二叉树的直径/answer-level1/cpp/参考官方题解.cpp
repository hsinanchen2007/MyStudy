### 解题思路
1.参考官方题解
2.通过递归遍历，判断每个节点的深度，
并找打左右深度的最大值

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
    //记录下每个节点左右深度之和中的最大值
    int res=0;
    int diameterOfBinaryTree(TreeNode* root) {
         depth(root);
         return res;
    }
    int depth(TreeNode* node)
    {
        if(node == NULL) return 0;
        int l = depth(node->left);
        int r = depth(node->right);
        res = max(res,l+r);
        return max(l,r)+1;
    }
};
```