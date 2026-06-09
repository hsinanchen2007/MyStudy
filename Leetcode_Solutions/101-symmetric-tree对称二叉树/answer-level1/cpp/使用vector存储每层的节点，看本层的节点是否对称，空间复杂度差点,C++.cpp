

    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> vec;
        
        if (!root)
            return true;
         
        vec.push_back(root->left);
        vec.push_back(root->right);
        
        while (1) {
            vector<TreeNode*> tmp;
            int sz = vec.size();
            if (isVecAllNull(vec))
                return true;
            
            if (sz % 2 == 1)
                return false;
            
            for (int i = 0; i < sz/2; i++) {
                if (vec[i] == NULL && vec[sz-i-1] != NULL)
                    return false;
                
                if (vec[i] != NULL && vec[sz-i-1] == NULL)
                    return false;
                
                if (vec[i] == NULL && vec[sz-i-1] == NULL)
                    continue;
                
                if (vec[i]->val != vec[sz-i-1]->val)
                    return false;
            }
            for (int i = 0; i < sz; i++) {
                if (vec[i]) {
                    tmp.push_back(vec[i]->left);
                    tmp.push_back(vec[i]->right);
                }
            }
            
            vec.clear();
            for (int i = 0; i < tmp.size(); i++) {
                vec.push_back(tmp[i]);                 
            }
        }
        return true;
    }


    bool isVecAllNull(vector<TreeNode*>& v) {
        for (int i = 0; i < v.size(); i++)
            if (v[i] != NULL)
                return false;
        
        return true;
    }
