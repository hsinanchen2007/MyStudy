### 解题思路
此处撰写解题思路

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
    int MaxDepth(TreeNode* root,int &num)
    {
        if(root == NULL)
        {
            return 0;
        }
        int l = MaxDepth(root->left,num);
        int r = MaxDepth(root->right,num);
        num = max(num,l + r + 1); // 如果 l + r + 1 主函数return num - 1 初始num设置为1
        return (max(l,r) + 1); // 返回树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int num = 1; // 初始值为1
        MaxDepth(root,num);
        return num - 1; // return值为 num - 1
    }
};
```