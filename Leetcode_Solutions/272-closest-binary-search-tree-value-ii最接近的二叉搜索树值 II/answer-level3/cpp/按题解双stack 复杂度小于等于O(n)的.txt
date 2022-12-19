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
        long long dis = 0x3f3f3f3f3f;
        TreeNode* x;
        stack<TreeNode*> sl,sg;
        TreeNode* getGreat(){
            if(sg.empty())
                return nullptr;
            TreeNode* root = sg.top();
            sg.pop();
            if(root->right)
            {
                sg.push(root);
                root = root->right;
                sg.push(root);
                while(root->left)
                {
                    root = root->left;
                    sg.push(root);
                }
            }
            else{
                if(sg.empty())
                    return nullptr;
                TreeNode* t = sg.top();
                sg.pop();
                while(root!=t->left)
                {
                    root = t;
                    if(sg.empty())
                        return nullptr;
                    t = sg.top();
                    sg.pop();
                }
                sg.push(t);
                root=t;
            }
            return root;
        }
        TreeNode* getLess()
        {
            if(sl.empty())
                return nullptr;
            TreeNode* root = sl.top();
            sl.pop();
            if(root->left)
            {
                sl.push(root);
                root = root->left;
                sl.push(root);
                while(root->right)
                {
                    root = root->right;
                    sl.push(root);
                }
            }
            else{
                if(sl.empty())
                    return nullptr;
                TreeNode* t = sl.top();
                sl.pop();
                while(t&&root!=t->right)
                {
                    root = t;
                    if(sl.empty())
                        return nullptr;
                    t = sl.top();
                    sl.pop();
                }
                sl.push(t);
                root=t;
            }
            return root;
        }
        void find(TreeNode* root, double& target)
        {
            if(!root)
                return;
            sl.push(root);
            sg.push(root);
            long long t = abs(root->val-target);
            if(t<=dis)
            {
                dis = t;
                x = root;
            }
            if(t<1e-6)
                return;
            else if(root->val<target)
                find(root->right,target);
            else
                find(root->left,target);
        }
    public:
        vector<int> closestKValues(TreeNode* root, double target, int k) {
            if(!root)
                return {};
            vector<int> res;
            find(root,target);
            while(sg.top()!=x)
                sg.pop();
            while(sl.top()!=x)
                sl.pop();
            res.push_back(x->val);
            k--;
            TreeNode* l=nullptr,*r=nullptr;
            while(k)
            {
                // cout<<sl.size()<<','<<sg.size()<<endl;
                if(!l)
                    l = getLess();
                if(!r)
                    r = getGreat();
                if(l&&r)
                {
                    if(abs(l->val-target)>abs(r->val-target))
                    {
                        res.push_back(r->val);
                        r = nullptr;
                    }else
                    {
                        res.push_back(l->val);
                        l = nullptr;
                    }
                }else if(l)
                {
                    res.push_back(l->val);
                    l = nullptr;
                }
                else if(r){
                    res.push_back(r->val);
                    r = nullptr;
                }
                k--;
            }
            return res;
        }
    };