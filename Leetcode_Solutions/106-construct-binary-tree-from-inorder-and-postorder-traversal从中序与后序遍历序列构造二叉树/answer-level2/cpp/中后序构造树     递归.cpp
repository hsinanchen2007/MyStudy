### 解题思路
后序：从后往前遍历+先柚子树链接，再左子树链接，因为后序数组对应得根是先右根
前序：从前遍历，先左子树，再柚子树

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
         TreeNode* build(vector<int>& postorder, vector<int>& inorder,int& pos,int left,int right){
        if(pos<0||left>right) return 0;//结束条件，空或者越界的话，自然返回0
        int i=left;
        for(i;i<=right;i++){
            if(inorder[i]==postorder[pos]) break;//找到pos在中序中的位置
        }
        TreeNode* root=new TreeNode(postorder[pos]);//建立节点
        //根据中序判断此节点是否有左右子树，有则链接
        //先右再左
        if(i<right) root->right=build(postorder,inorder,--pos,i+1,right);
        if(i>left) root->left=build(postorder,inorder,--pos,left,i-1);//
        
        return root;//左右子树链接完后返回节点
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos=inorder.size()-1;//后序那么最后一个是根节点，所以从后往前遍历
        return build(postorder,inorder,pos,0,inorder.size()-1);
        //引用：pos因为在第一个递归结束，到第二个时候，pos也跟着变了，而left，right不跟着变，而是回到原样；   注意：引用：不可赋表达试，或者常数给它，所以++pos
    }
};
```