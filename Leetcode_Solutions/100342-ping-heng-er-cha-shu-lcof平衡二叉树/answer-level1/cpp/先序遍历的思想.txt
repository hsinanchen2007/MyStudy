### 解题思路
先序遍历的做法见代码注释，此题还有后序遍历的做法

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
        if(!root)return true;
        if(abs(getHeight(root->left) - getHeight(root->right)) <= 1)  //当前根节点已经满足平衡
            return isBalanced(root->left) && isBalanced(root->right);  //递归到左右子树判断是否满足平衡
        return false;
    }
    int getHeight(TreeNode *x)
    {
        if(!x)return 0;  //空树深度为0
        int leftDepth = getHeight(x->left);  //左子树深度
        int rightDepth = getHeight(x->right);  //右子树深度
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);  //左右子树高度为左右子树最高高度+1
    }
};
```