### 解题思路


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
       if(preorder.size()==0||inorder.size()==0||preorder.size()!=inorder.size()) return nullptr;

       return findroot(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* findroot(vector<int>& preorder,vector<int>& inorder,int pbegin,int pend,int ibegin,int iend)
    {
        TreeNode* root=new TreeNode(preorder[pbegin]);
        
        //找到pbegin在inorder中的位置
        int i=ibegin;
        while(inorder[i]!=preorder[pbegin])
        {
            ++i;
        }
        int len=i-ibegin;
        if(len>0)//左边长度大于0
        root->left=findroot(preorder,inorder,pbegin+1,pbegin+1+len-1,ibegin,i-1);
        if(iend-i>0)//右边长度大于0
        root->right=findroot(preorder,inorder,pbegin+len+1,pend,i+1,iend);
        return root;

    }

};
```