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
    TreeNode* help(vector<int>& pre, vector<int>& ino,int pleft,int pright,int ileft,int iright)
    {
        int index;
        int leaf1=pleft+1;
        int leaf2;
        TreeNode* tree=new TreeNode(0);
        tree->val=pre[pleft];
        for(int i=ileft;i<=iright;i++)
            if(ino[i]==tree->val)
            {
                index=i;
                break;
            }
        leaf2=index-ileft+pleft+1;

        if(index>ileft)
            tree->left=help(pre,ino,leaf1,leaf2-1,ileft,index-1);
        if(index<iright)
            tree->right=help(pre,ino,leaf2,pright,index+1,iright);
        return tree;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())return NULL;
        return help(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);

    }
};
```