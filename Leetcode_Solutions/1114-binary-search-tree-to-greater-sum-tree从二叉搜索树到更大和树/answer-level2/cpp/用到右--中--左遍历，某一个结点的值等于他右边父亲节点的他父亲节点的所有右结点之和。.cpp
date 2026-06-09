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
    TreeNode* bstToGst(TreeNode* root) {  //右边的比左边的都大
        if(root==nullptr) return root;
        int key=0;
        DFS(root,key);
        return root;
    }
    void DFS(TreeNode *root,int &key){
        if(root==nullptr) return ;
        DFS(root->right,key);
        key=key+root->val;
        root->val=key;
        DFS(root->left,key);
    }
};
```