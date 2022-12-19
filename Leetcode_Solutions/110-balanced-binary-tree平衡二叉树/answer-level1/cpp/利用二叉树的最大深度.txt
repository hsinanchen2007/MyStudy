### 解题思路
利用二叉树的最大深度

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
        bool flag = true;
        maxDepth(root,flag);
        return flag;
    }
    int maxDepth(TreeNode* root,bool & flag) {
        if(root == NULL){
            return 0;
        }
        int left = maxDepth(root->left,flag);
        int right = maxDepth(root->right,flag);        
        //如果不满足平衡二叉树，就设置标志位
        if(abs(left-right) > 1)
            flag = false;
        return (left >= right)?left+1:right+1;
    }
};
```