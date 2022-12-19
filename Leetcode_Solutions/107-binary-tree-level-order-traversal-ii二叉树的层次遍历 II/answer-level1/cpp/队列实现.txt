```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>vi;
        vector<int>f;
        queue<TreeNode*>s;
        s.push(root);
        int last=s.size(),first=0,end=last;
        while(last!=first)
        {
            auto x=s.front();
            first++;
            s.pop();
            f.push_back(x->val);
            if(x->left){s.push(x->left),++end;}
            if(x->right){s.push(x->right);++end;}
            if(last==first){last=end;vi.push_back(f);f={};}
        }
        reverse(vi.begin(),vi.end());
        return vi;
    }
};
```

