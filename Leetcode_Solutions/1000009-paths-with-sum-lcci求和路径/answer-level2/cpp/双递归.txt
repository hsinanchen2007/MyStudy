### 解题思路
第一层递归遍历每个节点，第二层递归遍历每个每个结点开始的路径

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
int targetMy;
int result;
    int pathSum(TreeNode* root, int sum) {
        targetMy=sum;
        result=0;
        preBianLi(root);
        return result;
    }
   void preBianLi(TreeNode* root)
   {
       if(root==NULL)
       return;
       preBianLi(root->left);
       findRoad(root,root->val);
       preBianLi(root->right);
   }
   void findRoad(TreeNode *root,int sum)
   {
        
       if(sum==targetMy)
       {
           result++;
       }
       if(root->left)
       findRoad(root->left,sum+root->left->val);
        if(root->right)
        findRoad(root->right,sum+root->right->val);

   }
};
```