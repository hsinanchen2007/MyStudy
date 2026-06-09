### 解题思路
思路就是最大深度的思路，陷阱就是 如 1 2 这种情况值得注意

首先求出左子树的最小深度
再求出右子树的最小深度
重点：陷阱 要判断一棵树的根节点没有左，或者右子叶的话最小深度是rightDepth+leftDepth+1;

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
    int minDepth(TreeNode* root) 
    {
        if(root==NULL)
        return 0;

        int rightDepth=minDepth(root->right);
        int leftDepth=minDepth(root->left);
           
        

        if(root->left!=NULL&&root->right!=NULL)
         {
             return min(rightDepth,leftDepth)+1;
         }

         else
         {
             //陷阱 如1 2 这种情况如下处理
             return rightDepth+leftDepth+1;
         }
         
    }     
   
};
```