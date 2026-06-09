根据最大距离的节点数减去1 求最大距离
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int r = 0;
        int pnum = traverse(root, r);
        if(pnum<2) return 0;
       return pnum-1;

    }
    int traverse(TreeNode* root, int& r){
        if(root==nullptr){
            r=0;
            return 0;
        }
        int leftmax = traverse(root->left, r);
        int lmax = r;
        int rightmax = traverse(root->right, r);
        int rmax = r;
        int maxr = max(lmax+rmax+1, leftmax);
        maxr =  max(maxr, rightmax);
        r = max(lmax,rmax)+1;
        
        return maxr;

    }
};