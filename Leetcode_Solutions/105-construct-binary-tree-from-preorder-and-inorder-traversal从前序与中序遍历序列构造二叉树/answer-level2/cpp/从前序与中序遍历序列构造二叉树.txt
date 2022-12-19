### 解题思路
方法：采用递归

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0){
            return NULL;
        }
        return build(preorder,0,preorder.size()-1, inorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int pre_begin,int pre_end ,vector<int>& inorder,int in_begin,int in_end){
        TreeNode* root = new TreeNode(preorder[pre_begin]);
        int i=in_begin;
        while(i<=in_end && preorder[pre_begin]!=inorder[i]){
            i++;
        }
        int left=i-in_begin;
        int right=in_end-i;
        if(left>0){
           root->left=build(preorder,pre_begin+1,pre_begin+left,inorder,in_begin,in_begin+left-1);
        }
        if(right>0){
           root->right=build(preorder,pre_begin+left+1,pre_end,inorder,i+1,in_end);//i+right=in_end
        }
        return root;
    }
};
```