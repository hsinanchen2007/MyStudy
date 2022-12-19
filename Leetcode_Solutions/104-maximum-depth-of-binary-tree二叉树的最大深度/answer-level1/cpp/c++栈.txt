```
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(root==NULL) return 0;
        stack <TreeNode*>s1;
        stack<int>s2;
        int max=0,cur=1;
        s1.push(root);
        s2.push(cur);
        while(!s1.empty())
        {
            TreeNode* t=s1.top();
            cur=s2.top();
            s1.pop();
            s2.pop();
            if(cur>max) max=cur;
            if(t->left!=NULL) 
            {
                s1.push(t->left);
                s2.push(cur+1);
            }
            if(t->right!=NULL)
            {
                s1.push(t->right);
                s2.push(cur+1);
            }
        }
        return max;
    }
};
```
