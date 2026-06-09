vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* current=root;
        while(current){
            ans.push_back(current->val);//中序遍历此句放在下面的if语句中
            if(!current->left){
                current=current->right;
            }
            else{
                TreeNode* temp=current->left;
                while(temp->right)
                    temp=temp->right;
                temp->right=current->right;//中序遍历此处为temp->right=current；
                TreeNode* p=current;
                current=current->left;
                p->left=NULL;
            }
        }
        return ans;
    }