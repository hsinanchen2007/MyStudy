### 简单的递归

找到先序数组中的第一个节点，作为根，中序数组中根左边的作为左子树，右边作为右子树，依次递归下去
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

    void fun(vector<int>& preorder,vector<int>& inorder,int start,int end,int &n,TreeNode* &p)
    {
        int i;
        for( i=start;i<end;i++)
            if(preorder[n]==inorder[i])
                break;
        if(i==end)
            return ;
        p=new TreeNode(preorder[n]);
        n++;
        fun(preorder,inorder,start,i,n,p->left);
        fun(preorder,inorder,i+1,end,n,p->right);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return NULL;
        TreeNode *p;
        int n=0;
        int N=inorder.size();
        fun(preorder,inorder,0,N,n,p);
        return p;
    }
};
```