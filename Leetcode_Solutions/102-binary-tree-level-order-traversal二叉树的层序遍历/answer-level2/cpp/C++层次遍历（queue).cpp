在各层末节点设置checkpoint以区分各层

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        vector<int> tmp;
        TreeNode* checkpoint=root;
        if(root==nullptr)
            return ret;
        else
            q.push(root);
        while(!q.empty()){
            TreeNode *p=q.front();
            if(p->left)
                q.push(p->left);
            if(p->right)
                q.push(p->right);
            tmp.push_back(p->val);
            q.pop();
            if(p==checkpoint){
                ret.push_back(tmp);
                checkpoint=q.back();
                tmp.clear();
            }
        }
        return ret;
    }
};