### 解题思路
因为后序的最后一个总是根结点，令i在中序中找到该根结点，则i把中序分为两部分，左边是左子树，右边是右子树。因为是输出先序（根左右），所以先打印出当前根结点，然后打印左子树，再打印右子树。左子树在后序中的根结点为root – (end – i + 1)，即为当前根结点-(右子树的个数+1)。左子树在中序中的起始点start为start，末尾end点为i – 1.右子树的根结点为当前根结点的前一个结点root – 1，右子树的起始点start为i+1，末尾end点为end。

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return preorder(0,inorder.size()-1,0,inorder.size()-1,inorder,postorder);
    }

    TreeNode* preorder(int left,int right,int leftpost,int rightpost,vector<int>&in,vector<int>&post)
     {
        if(left>right){
            return NULL;
        }
        TreeNode* root=new TreeNode(post[rightpost]);
        int i=left;
        while(i<=right&&in[i]!=post[rightpost]){
            i++;
        }
        int len=i-left;
        root->left=preorder(left,i-1,leftpost,leftpost+len-1,in,post);
        root->right=preorder(i+1,right,leftpost+len,rightpost-1,in,post);
        return  root;
     }
};
```