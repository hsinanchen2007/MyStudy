空间换时间，比递归快很多
    
    bool findPath(vector<TreeNode*>& path,TreeNode* root,TreeNode* target){
        if(root==nullptr){
            return false;
        }
        path.push_back(root);
        if(root==target||findPath(path,root->left,target)||findPath(path,root->right,target)){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1,path2;
        if(!findPath(path1,root,p)||!findPath(path2,root,q)){
            return nullptr;
        }
        int i=min(path1.size(),path2.size())-1;
        while(i>0&&path1[i]!=path2[i]){
            i--;
        }
        return path1[i];
    }