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
    int res;
    int maxDepth(TreeNode* root) {
        count(root,0);
        return res;
    }
    void count(TreeNode *root,int len){
        if(root==NULL) return;
        if(root!=NULL) {
            len++;res=max(res,len);
        }
        count(root->left,len);
        count(root->right,len);
    }
};
```