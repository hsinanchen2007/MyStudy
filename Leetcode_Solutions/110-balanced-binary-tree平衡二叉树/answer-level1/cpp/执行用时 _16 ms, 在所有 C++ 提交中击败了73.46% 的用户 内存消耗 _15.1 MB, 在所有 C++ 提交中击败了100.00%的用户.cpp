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
    public:
        bool isBalanced(TreeNode* root)
        {
              if(root==NULL)
                return true;

            if( judge(root->left,root->right))
                 return   isBalanced(root->left) &&    isBalanced(root->right);   
            else
                return false;
            
        }
        bool judge(TreeNode* t1,TreeNode* t2)
        {
            int count1=get_nodes(t1);
            int count2=get_nodes(t2);
            if(abs(count1-count2)<2)
                return true;
            else
                return false;
        }
        int get_nodes(TreeNode* t)
        {
            if (t==NULL)
                return 0;
            return max(get_nodes(t->left),get_nodes(t->right))+1;
        }
    };
```