1.层次遍历(BFS)
通常层次遍历使用一个队列，开始压入非空的头节点，然后依次将头部非空子节点压入队列，将头部节点弹出，跟这道题有些不同，需要记录深度。
使用vector<vector<TreeNode*>> s将每一层节点都记录下来，最后看s的size()
我使用一个vector<TreeNode> a来记录当层节点，vector<TreeNode> b记录下一层节点，由此来进行推进，a的size()用来跳出循环
```
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        vector<vector<TreeNode*>> s;        
        vector<TreeNode*> a;
        a.push_back(root);
        s.push_back(a);
        int i = 1;
        while(a.size()!=0){
            i++;
            int flag = 0;
            vector<TreeNode*> b;
            for(int i=0;i<a.size();i++){
                if(a[i]!=NULL){
                    b.push_back(a[i]->left);
                    b.push_back(a[i]->right);
                }
            }
            s.push_back(b);
            a = b;
        }
        return s.size()-2;
    }
```
2.递归
搞清楚递归停止条件
```
int maxDepth(TreeNode* root) {
    if(root==NULL)
        return 0;
    else
        return max(maxDepth(root->left),maxDepth(root->right))+1;
}
```


