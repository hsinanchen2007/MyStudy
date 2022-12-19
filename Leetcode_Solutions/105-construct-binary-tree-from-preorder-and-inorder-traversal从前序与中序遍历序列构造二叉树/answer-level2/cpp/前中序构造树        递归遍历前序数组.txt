### 解题思路

前序数组第一个就是根节点
由中序判断根节点的左右子树存在否，存在则前序的下一个数就是相应的左右根
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int& pos,int left,int right){
        if(pos>=preorder.size()) return 0;//结束条件，空的话，自然返回0
        int i=left;
        for(i;i<=right;i++){
            if(inorder[i]==preorder[pos]) break;//找到pos在中序中的位置
        }
        TreeNode* root=new TreeNode(preorder[pos]);//建立节点
        //根据中序判断此节点是否有左右子树，有则链接
        if(i>left) root->left=build(preorder,inorder,++pos,left,i-1);//
        if(i<right) root->right=build(preorder,inorder,++pos,i+1,right);
        return root;//左右子树链接完后返回节点
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos=0;
        return build(preorder,inorder,pos,0,inorder.size()-1);
        //引用：pos因为在第一个递归结束，到第二个时候，pos也跟着变了，而left，right不跟着变，而是回到原样；   注意：引用：不可赋表达试，或者常数给它，所以++pos
    }
};
```