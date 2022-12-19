### 解题思路
此处撰写解题思路

### 代码
执行用时 :
4 ms
, 在所有 C++ 提交中击败了
66.95%
的用户
内存消耗 :
10.1 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

指针指的位置交换就可以了，不是数值交换，是指针。

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

    TreeNode* mirrorTree(TreeNode* root)
     { 
         TreeNode *a;
         a=root;   
         mirror(root);
         return a;
    }
  void  mirror(TreeNode* a)
    {
        if(a==NULL)
        {
            return;
        }
        else if(a->left==NULL&&a->right==NULL)
        {
            return;

        }
        else
        {
            TreeNode*temp;
            temp=a->left;
            a->left=a->right;
            a->right=temp;
            mirror(a->left);
            mirror(a->right);
        }

        




    }










};
```