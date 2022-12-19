```cpp
    /***********recurisive method********************/
    /*
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root,result);
        return result;
    }
    void inorder(TreeNode* root,vector<int>& res){
        if(nullptr==root) return;
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
        return;
    }*
    /
    /*******Iteration method***********************/
    vector<int> inorderTraversal(TreeNode* root){
        if(nullptr==root) return vector<int>();
        stack<TreeNode*> q;
        vector<int>res;
        auto node=root;
        while(nullptr!=node||!q.empty()){
            while(node!=nullptr){
                q.push(node);
                node=node->left;
            }
            auto top=q.top();
            q.pop();
            res.emplace_back(top->val);
            node=top->right;
        }
        return res;
    }
```
