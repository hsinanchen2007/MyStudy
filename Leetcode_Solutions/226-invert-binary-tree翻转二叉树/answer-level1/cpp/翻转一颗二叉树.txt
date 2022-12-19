### 解题思路
思路在于注重这个函数功能的宏观语义来实现功能，不要太在于递归的实现过程，
往往稍微分析哈原子问题就可判定你递归思路的问题

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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root==NULL)
            return NULL;

        invertTree(root->left);        //翻转左子树
        invertTree(root->right);       //反转右子树
        swap(root->left,root->right);  //反转后再交换了他们的左右根就实现了当前这棵树的反转

        return root;                   //最后返回这颗已经反转的二叉树；

    }
};
```