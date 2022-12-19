vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> tmp;
        TreeNode *ptr = root;
        while(true){
            // 从根结点开始遍历二叉树左子结点，并将前一个'根'结点入栈
            if(ptr){
                tmp.push(ptr);
                ptr = ptr->left;
            }
            // 当遍历至空结点,取出前一个'根'结点,将值加入结果，然后遍历该'根'结点右子节点
            else if(!tmp.empty()){
                ptr = tmp.top();
                tmp.pop();
                res.push_back(ptr->val);
                ptr = ptr->right;
            }
            // 当前指针为空，且栈中无结点指针说明遍历完毕
            else{
                break;
            }
        }
        return res;
    }