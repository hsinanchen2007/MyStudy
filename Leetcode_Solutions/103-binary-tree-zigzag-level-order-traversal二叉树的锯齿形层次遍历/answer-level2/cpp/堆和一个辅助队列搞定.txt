vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> resp_vec;
        
        if ( !root ) return resp_vec;
    
        stack<TreeNode*> stk;
        
        stk.push(root);
        
        bool is_left_to_right = false;
        
        while ( !stk.empty() )
        {
            
            int size = stk.size();
           
            vector<int> tmp_vec;
            
            queue<TreeNode *> tmp_queue;
            
            while(size--)
            {
                TreeNode * node = stk.top();
                
                if (node)
                {
                    tmp_vec.push_back(node->val);
                }

                stk.pop();
                
                if (is_left_to_right)
                {
                    if (node->right) tmp_queue.push(node->right);
                    
                    if (node->left) tmp_queue.push(node->left);
                }
                else
                {
                    if (node->left) tmp_queue.push(node->left);
                    
                    if (node->right) tmp_queue.push(node->right);
                }
            }
            
            while( !tmp_queue.empty() )
            {
                TreeNode * f = tmp_queue.front();
                
                if (f) stk.push(f);
                
                tmp_queue.pop();
            }
            
            resp_vec.push_back(tmp_vec);

            is_left_to_right = !is_left_to_right;
        }
        
        return resp_vec;
    }