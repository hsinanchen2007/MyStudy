### 解题思路
千万别忘记了不仅左子树与右子树的高度差的绝对值为一，还有左右子树都是平衡二叉树

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
class Solution 
{
private:
   int  treeMaxHeight(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        return max(treeMaxHeight(root->left),treeMaxHeight(root->right))+1;

    }

public:
    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL)
           return true;

        return (abs(treeMaxHeight(root->left)-treeMaxHeight(root->right))<=1&&isBalanced(root->left) &&
      isBalanced(root->right));
        

    }
};
```