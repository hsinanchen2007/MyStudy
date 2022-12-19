### 解题思路
两次搜索，每次搜索得出父节点以及节点深度。
对比两次搜索的结果得出答案。
![image.png](https://pic.leetcode-cn.com/adfd52ecd684adf86cd936bbcf7c5f9715402f848bef361ab319386aec326b7f-image.png)

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
    int parentx=0,parenty=0,depthx=0,depthy=0,d;
    void search(TreeNode* root,int& x,int& parent,int depth)
    {
       
       if(root->left)
       {
           if(root->left->val==x)
           {
               parent=root->val;
               d=depth+1;
               return;
           }
           search(root->left,x,parent,depth+1);
       }
       if(root->right)
       {
           if(root->right->val==x)
           {
               parent=root->val;
               d=depth+1;
               return;
           }
           search(root->right,x,parent,depth+1);
       }
       
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        search(root,x,parentx,depthx);
        depthx=d;
        d=0;
        search(root,y,parenty,depthy);
        depthy=d;
        if(depthx==depthy && parentx!=parenty)
         return true;
         return false;
    }
};
```