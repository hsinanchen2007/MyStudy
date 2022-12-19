### 解题思路
根据先序和中序构建二叉树，关键是递归方法的运用和边界的计算

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
        if(preorder.size()<1)
        return NULL;
        return process(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* process(vector<int>& preorder,int pi,int pj, vector<int>& inorder,int ni,int nj)
    {
        if(pi>pj)
            return NULL;
        TreeNode* head=new TreeNode(preorder[pi]);
        int i=0;
        for(i=ni;i<=nj;i++)
        {
            if(inorder[i]==preorder[pi])
                break;
        }
        //中序遍历数组中左子树长度i-ni,右子树长度nj-i
        head->left=process(preorder,pi+1,pi+i-ni,inorder,ni,i-1);
        head->right=process(preorder,pj-nj+i+1,pj,inorder,i+1,nj);
        return head;
    }
};
```