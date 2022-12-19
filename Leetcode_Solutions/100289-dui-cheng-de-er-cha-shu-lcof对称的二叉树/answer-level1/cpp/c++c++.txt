### 解题思路
此处撰写解题思路
执行用时 :
12 ms
, 在所有 C++ 提交中击败了
30.32%
的用户
内存消耗 :
17.7 MB
, 在所有 C++ 提交中击败了
100.00%
的用户
要画图理解一下，左子树的左子树等于右子树的右子树大致这个思路。只要当中有空的肯定不对称，一起空说明结束

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
    bool isSymmetric(TreeNode* root) {


       if(root)
       return isright(root->left,root->right);
       else
       return true;
        





    }
   bool isright(TreeNode* a,TreeNode* b)
   {
        if(!a&&!b)
        {
            return true;
        }
        else if(!a||!b)
        {
            return false;
        }

       if(a->val==b->val)
       {

           return isright(a->left,b->right)&&isright(a->right,b->left);
       }
       else
       return false;




   }





};
```