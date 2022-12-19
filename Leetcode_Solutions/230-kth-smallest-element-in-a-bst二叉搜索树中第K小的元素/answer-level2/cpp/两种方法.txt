思路都是中序遍历
非递归版本：

    int kthSmallest(TreeNode* root, int k) {
        TreeNode* current=root;
        stack<TreeNode*> s;
        while(current!=nullptr||!s.empty()){
            while(current!=nullptr){
                s.push(current);
                current=current->left;
            }
            current=s.top();
            s.pop();
            if(k==1){
                return current->val;
            }
            k--;
            current=current->right;
        }
        return -1;
    }

递归版本：

    void BackTrack(TreeNode* root,int k,int& result,int& i){
        if(root!=nullptr){
            BackTrack(root->left,k,result,i);
            i++;
            if(k==i){
                result=root->val;
                return;
            }
            BackTrack(root->right,k,result,i);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int result,i=0;
        BackTrack(root,k,result,i);
        return result;
    }