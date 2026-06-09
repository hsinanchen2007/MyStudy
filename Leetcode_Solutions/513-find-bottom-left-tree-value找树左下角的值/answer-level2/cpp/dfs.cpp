### 解题思路
此处撰写解题思路
两次dfs一次得到树的高度，一次得到value
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
    int value,flag=0;
    int getheight(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        return max(getheight(root->left),getheight(root->right))+1;
    }
    void dfs(TreeNode *root,int height,int curhei){
        if(flag==1||root==NULL)   //flag用于找到value后回溯所有递归层
           return;
        if(height==curhei){
           value=root->val;
           flag=1;
           return;
        }
        dfs(root->left,height,curhei+1);
        dfs(root->right,height,curhei+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int height=getheight(root);
        dfs(root,height,1);
        return value;
    }
};
```