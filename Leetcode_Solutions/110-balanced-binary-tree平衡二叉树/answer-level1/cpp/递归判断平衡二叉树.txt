### 解题思路
递归思路很容易想到
一开始错误的地方是忽略了“每个节点”，以为只是左右子树高度差小于1
所以加上了 判断左右子树是否为平衡二叉树

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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if(abs(depth(root->left)-depth(root->right))<=1)
        {
            if(isBalanced(root->left) && isBalanced(root->right))
                return true;
        }     
        return false;
    }

    int depth(TreeNode* t)
    {
        int d = 0;
        if(t == NULL)
            return 0;
        return max(depth(t->left), depth(t->right))+1;
    }
};
```