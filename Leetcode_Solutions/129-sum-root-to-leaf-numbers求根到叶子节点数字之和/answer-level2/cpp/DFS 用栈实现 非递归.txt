```
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        TreeNode* p=root;
        stack<pair<TreeNode*,int>> s;
        int su=0;
        while(!s.empty()||p)
        {
            while(p)
            {
                su=su*10+p->val;
                s.push(pair<TreeNode*,int>(p,su));
                p=p->left;
            }
            p=s.top().first;
            su=s.top().second;
            s.pop();
            if(p->right==NULL&&p->left==NULL) ans=ans+su;
            p=p->right;
        }
        return ans;
    }
};
```
