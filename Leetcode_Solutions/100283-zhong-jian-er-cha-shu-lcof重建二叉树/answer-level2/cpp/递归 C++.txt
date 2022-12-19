1. 前序遍历首元素为根结点`[root,***]`
2. 以根结点划分中序遍历`[l_i,root,r_i]`，`l_i`为左子树的中序遍历序列，`r_i`为右子树大中序遍历序列
3. 根据root在中序序列中的index，可计算出左子树遍历序列的长度为index，将前序遍历划分为左右子树序列`[root,l_p,r_p]`
4. 以`(l_p,l_i)`和`(r_p,r_i)`递归生成左子树及右子树
```
class Solution {
    TreeNode* helper(vector<int>& pre_v,int plo, int phi, vector<int>& in_v, int ilo, int ihi){
        if(plo>phi || ilo>ihi) return nullptr; //区间为空，返回空指针
        int root_val = pre_v[plo]; //前序遍历首元素为根结点的值
        TreeNode* root = new TreeNode(root_val);
        //根结点在中序遍历中的index
        int i = find(in_v.begin(), in_v.end(), root_val)-in_v.begin(); 
        //以root_val在中序遍历中的index划分左子树
        root->left = helper(pre_v, plo+1,plo+i-ilo,in_v,ilo,i-1);
        //以root_val在中序遍历中的index划分右子树
        root->right = helper(pre_v,plo+i-ilo+1,phi,in_v,i+1,ihi);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        TreeNode* root=helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        return root;
    }
};
```
