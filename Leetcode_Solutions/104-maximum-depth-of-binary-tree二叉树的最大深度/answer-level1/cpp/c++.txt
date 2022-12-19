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
private:
    int max_depth=0;
public:
    void getMaxDepth(TreeNode* root,int current_deep){
        if(root->left==NULL&&root->right==NULL)max_depth=max(max_depth,current_deep);
        if(root->left!=NULL)getMaxDepth(root->left,current_deep+1);
        if(root->right!=NULL)getMaxDepth(root->right,current_deep+1);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        getMaxDepth(root,1);
        return max_depth;
    }
};
```