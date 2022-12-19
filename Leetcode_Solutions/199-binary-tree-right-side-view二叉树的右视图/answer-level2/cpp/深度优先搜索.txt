    class Solution {
    private:
        int TreeDeep;
        void leftview(TreeNode* root,vector<int>& val,int deep){
            if(root == NULL)
                return;
            deep++;
            if(deep > TreeDeep)
                val.push_back(root->val);
            //更新树的深度，后续搜索时，要大于当前深度才可
            if(root->right == NULL && root->left == NULL){
                TreeDeep = deep > TreeDeep ? deep:TreeDeep;
                return;
            }
            if(root->right != NULL)
                leftview(root->right,val,deep);
            if(root->left != NULL)
                leftview(root->left,val,deep);
            return;      
        }
    public:
        vector<int> rightSideView(TreeNode* root) {
            vector<int> res;
            if(root == NULL)
                return res;
            int dep = 0;
            TreeDeep = 0;
            leftview(root,res,dep);
            return res;
        }
    };