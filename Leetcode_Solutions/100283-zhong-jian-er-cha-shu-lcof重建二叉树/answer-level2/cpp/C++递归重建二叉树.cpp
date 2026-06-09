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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0&&inorder.size()==0) return nullptr;
        if(preorder.size()!=inorder.size()) return nullptr;
        TreeNode* root=construct(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
        return root;
    }
    TreeNode* construct(vector<int>& preorder,vector<int>& inorder,int i,int j,int m,int n)
    {
        if(i<=j&&m<=n){
        TreeNode* a=new TreeNode(preorder[i]);
        int k=m;
        while(inorder[k]!=preorder[i]) k++;
        a->left=construct(preorder,inorder,i+1,i+k-m,m,k-1);
        a->right=construct(preorder,inorder, i+k-m+1, j,k+1,n);
        return a;
        }
        return nullptr;
        
    }

};
```