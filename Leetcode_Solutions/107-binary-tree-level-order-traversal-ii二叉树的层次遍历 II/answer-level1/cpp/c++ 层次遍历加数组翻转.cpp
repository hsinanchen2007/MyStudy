class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> list;
        queue<TreeNode*>q;
        if(root == nullptr)
            return list;
        
        q.push(root);
        
        while(!q.empty())
        {
            int length = q.size();
            vector<int> _list;
            for(int i = 0; i < length; ++i)
            {
                TreeNode* tmp = q.front();
                q.pop();
                _list.push_back(tmp->val);
                
                if(tmp->left)
                {
                    q.push(tmp->left);
                }
                if(tmp->right)
                {
                    q.push(tmp->right);
                }
            }
            list.push_back(_list);
        }
        
        for(size_t i = 0; i < (list.size() + 1) / 2; i++)
        {
            vector<int> temp = list[i];
            list[i] = list[list.size() - i -1];
            list[list.size() - i - 1] = temp;
        }
        return list;
        
    }
};