
执行用时 :12 ms, 在所有 cpp 提交中击败了95.21%的用户
内存消耗 :20.3 MB, 在所有 cpp 提交中击败了95.64%的用户

用划定边界的方法递归，注意样例中有数据INT_MAX和INT_MIN，改用long型的边界即可

    bool isValid(TreeNode* current,long left,long right){
        if(current==nullptr) return true;
        else if(current->val<=left||current->val>=right) return false;
        return isValid(current->left,left,current->val)&&isValid(current->right,current->val,right);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MIN,LONG_MAX);
    }