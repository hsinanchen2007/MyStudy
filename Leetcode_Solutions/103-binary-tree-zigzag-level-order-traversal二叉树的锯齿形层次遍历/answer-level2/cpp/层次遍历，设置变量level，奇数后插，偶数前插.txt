```
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > vec;
        queue<TreeNode*> q;
        TreeNode* p;
        int level=0;
        if(root==NULL) return vec;
        q.push(root);

        while(!q.empty()){
            level++;
            int size=q.size();
            vector<int> s;
            for(int i=0;i<size;i++){
                p=q.front();
                q.pop();
                int val=p->val;
                if(level%2==1){
                    s.push_back(val);
                }else{
                    s.insert(s.begin(),val);
                }
                if(p->left!=NULL) q.push(p->left);
                if(p->right!=NULL) q.push(p->right);
            }
            vec.push_back(s);
        }
        return vec;

    }
```
