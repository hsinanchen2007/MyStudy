```
class Solution {
public:
    void buildT(vector<int>& preorder, vector<int>& inorder, TreeNode* &p, int low_pre, int high_pre, int low_in, int high_in){
        if(low_in > high_in){
            return;
        }
        p = new TreeNode(preorder[low_pre]);
        int idx_2;
        for(int i=low_in;i<=high_in;i++){
            if(inorder[i] == p->val){
                idx_2 = i;
                break;
            }
        }
        int left_interval = idx_2 - low_in;
        int right_interval = high_in - idx_2;
        buildT(preorder, inorder, p->left, low_pre + 1, low_pre + left_interval, low_in, idx_2 - 1);
        buildT(preorder, inorder, p->right, low_pre + left_interval + 1, low_pre + left_interval + right_interval, idx_2 + 1, high_in);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n==0)
            return NULL; 
        TreeNode* root;
        buildT(preorder, inorder, root, 0, n-1, 0, n-1);
        return root;
    }
};
```
