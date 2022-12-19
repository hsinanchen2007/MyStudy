# 本方法使用了101 大小的list
一开始我是觉得直接遍历会比较方便一些。后来发现原来节点数在2-100之间，那么就简单了而且节点值为唯一，所以想到使用bool的vector去做存储操作；
另外就是使用了一个操作就是，本行如果是兄弟节点就在上一行都遍历过了
这里张贴代码
`
bool isCousins(TreeNode* root, int x, int y) {
        if(!root)return false;
        vector<bool> list(101,false);
        if(list[root->val])return false;
        queue<TreeNode*> qs;
        qs.push(root);
        list[x]=list[y]=true;
        while(!qs.empty()){
            int size=qs.size();
            while(size-->0){
                TreeNode* n=qs.front();qs.pop();
                list[n->val]=false;
                if(n->left&&n->right){
                    if(list[n->left->val]&&list[n->right->val])return false;
                    qs.push(n->left);qs.push(n->right);
                }
                else {
                    if(n->left)qs.push(n->left);
                    if(n->right)qs.push(n->right);
                }
            }
            if(!list[x]||!list[y])return !list[x]&&!list[y];
        }
        return false;
    }
`