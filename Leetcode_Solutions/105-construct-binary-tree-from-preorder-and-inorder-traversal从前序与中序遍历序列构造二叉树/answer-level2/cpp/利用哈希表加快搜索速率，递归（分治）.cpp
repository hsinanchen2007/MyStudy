```
class Solution {
public:
    unordered_map<int,int>map_p,map_i;
    void build(TreeNode*root,vector<int>& preorder, vector<int>& inorder,int Lp,int Rp,int Li,int Ri){
        int pos=map_i[root->val];
        if(Lp<Rp&&Li<Ri){
            if(pos<Ri&&pos>Li){
                int leftend=Lp+pos-Li;
                root->left=new TreeNode(preorder[Lp+1]);
                build(root->left,preorder,inorder,Lp+1,leftend,Li,pos-1);
                root->right=new TreeNode(preorder[leftend+1]);
                build(root->right,preorder,inorder,leftend+1,Rp,pos+1,Ri);
            }
            if(pos==Ri){
                root->left=new TreeNode(preorder[Lp+1]);
                build(root->left,preorder,inorder,Lp+1,Rp,Li,Ri-1);
            }
            if(pos==Li){
                root->right=new TreeNode(preorder[Lp+1]);
                build(root->right,preorder,inorder,Lp+1,Rp,Li+1,Ri);
            }
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0)return NULL;
        TreeNode*root=new TreeNode(preorder[0]);
        for(int i=0;i<preorder.size();i++){
            map_p[preorder[i]]=i;
            map_i[inorder[i]]=i;
        }
        build(root,preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
        return root;
    }
};
```
