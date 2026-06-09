层序遍历A树的每个节点，判断是否和B树根节点相同。
相同的时候就DFS，按照先序遍历的顺序递归判断。
```
class Solution {
public:
    bool judge(TreeNode *p,TreeNode *b){
        if (!p)
		    return false;
        if(p->val!=b->val)
            return false;
        if(b->left)
            if(!judge(p->left,b->left))
                return false;
        if(b->right)
            if(!judge(p->right,b->right))
                return false;
        return true;
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==NULL)
            return false;
        queue<TreeNode*> que;
        que.push(A);
        bool res=false;
        while(!que.empty()){
            TreeNode *p=que.front();
            if(p->val==B->val)
                res=judge(p,B);
            if(p->left)
                que.push(p->left);
            if(p->right)
                que.push(p->right);
            que.pop();
        }
        return res;
    }
};
```
