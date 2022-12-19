按照自己的思路写了个BFS，哪里可以优化的欢迎提出宝贵意见。


```
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL||(root->left==NULL&&root->right==NULL)) return false;
        queue<pair<int,TreeNode*>> que;
        if(root->left!=NULL) que.push(make_pair(root->val,root->left));
        if(root->right!=NULL) que.push(make_pair(root->val,root->right));
        int len,father,t,flat=0;
        TreeNode* tmp;
        while(!que.empty()){
            len=que.size();
            for(int i=0;i<len;i++){
                father=que.front().first;
                tmp=que.front().second;
                que.pop();
                if(tmp->val==x||tmp->val==y){
                    if(flat==0){
                        t=father;
                        flat=1;
                    }
                    else{
                        if(t!=father) return true;
                        else return false;
                    }
                }
                else{
                    if(tmp->left!=NULL) que.push(make_pair(tmp->val,tmp->left));
                    if(tmp->right!=NULL) que.push(make_pair(tmp->val,tmp->right));
                }
            }
            if(flat==1) return false;
        }
        return false;
    }
};
```


