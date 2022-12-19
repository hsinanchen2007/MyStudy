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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL)
        return NULL;  
        return DFS(root,target);
    }
    TreeNode* DFS(TreeNode* root, int target){
        if(root==NULL)
        return NULL;
        root->left=DFS(root->left,target);  //注意：这里需要赋值，将你子节点赋给当前节点。
        root->right=DFS(root->right,target);
        if(root->left==NULL&&root->right==NULL&&root->val==target)
            root=NULL;//为空                //这里使用root=NULL;
        return root;
    }
};
```