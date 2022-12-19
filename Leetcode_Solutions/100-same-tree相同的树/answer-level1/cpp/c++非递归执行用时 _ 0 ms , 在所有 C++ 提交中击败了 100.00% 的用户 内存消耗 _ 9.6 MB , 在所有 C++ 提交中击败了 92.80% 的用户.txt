`````
 class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode *cur1=p;
        TreeNode *cur2=q;
        stack<TreeNode *>s1;
        stack<TreeNode *>s2;
        if(cur1)
        s1.push(cur1);
        if(cur2)
        s2.push(cur2);
        while(!s1.empty()&&!s2.empty())
        {
            if(s1.top()->val!=s2.top()->val) return false;
            if(((s1.top()->left==NULL)&&(s2.top()->left!=NULL))||((s1.top()->left==NULL)&&(s2.top()->left!=NULL))) return false;
            if(((s1.top()->right==NULL)&&(s2.top()->right!=NULL))||((s1.top()->right==NULL)&&(s2.top()->right!=NULL))) return false;
            cur1=s1.top();
            cur2=s2.top();
            s1.pop();s2.pop();
            if(cur1->left)
            s1.push(cur1->left);
             if(cur1->right)
            s1.push(cur1->right);
             if(cur2->left)
            s2.push(cur2->left);
             if(cur2->right)
            s2.push(cur2->right);
        }
        if(s1.empty()&&s2.empty()) 
            return true; 
        else 
            return false;     
    }
};
```
