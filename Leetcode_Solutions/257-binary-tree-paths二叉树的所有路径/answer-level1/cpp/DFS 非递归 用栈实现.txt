`````
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL) return ans;
        TreeNode* p=root;
        stack<pair<TreeNode*,string>> s;
        string str;
        while(!s.empty()||p)
        {
            while(p)
            {
                if(p==root) str=str+to_string(p->val);
                else str=str+"->"+to_string(p->val);
                s.push(pair<TreeNode*,string>(p,str));
                p=p->left;
            }
            p=s.top().first;
            str=s.top().second;
            s.pop();
            if(p->right==NULL&&p->left==NULL) ans.push_back(str);
            p=p->right;
        }
        return ans;
    }
};
```
