class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        deque<TreeNode*> d;
        d.push_back(root);
        int flag = 1;
        while(!d.empty()){
            int s = d.size();
            vector<int> sub;
            while(s){
                if(flag){
                    TreeNode* tmp = d.front();
                    d.pop_front();
                    if(tmp->left) d.push_back(tmp->left);
                    if(tmp->right) d.push_back(tmp->right);
                    sub.push_back(tmp->val);
                }
                else{
                    TreeNode* tmp = d.back();
                    d.pop_back();
                    if(tmp->right) d.push_front(tmp->right);
                    if(tmp->left) d.push_front(tmp->left);
                    sub.push_back(tmp->val);
                }
                s--;
            }
            flag = 1 - flag;
            res.push_back(sub);
        }
        return res;
    }
};