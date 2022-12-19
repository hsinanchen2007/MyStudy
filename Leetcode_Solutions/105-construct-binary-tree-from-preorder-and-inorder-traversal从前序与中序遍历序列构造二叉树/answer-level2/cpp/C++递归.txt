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
TreeNode *func(vector<int>& preorder, vector<int>& inorder,int i,int j){
    if(i>j)return NULL;
    int k=i;
    while(inorder[k]!=preorder.front())k++;
    preorder.erase(preorder.begin());
    TreeNode *node=new TreeNode(inorder[k]);
    node->left=func(preorder,inorder,i,k-1);
    node->right=func(preorder,inorder,k+1,j);
    return node;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return func(preorder,inorder,0,inorder.size()-1);
    }
};
```