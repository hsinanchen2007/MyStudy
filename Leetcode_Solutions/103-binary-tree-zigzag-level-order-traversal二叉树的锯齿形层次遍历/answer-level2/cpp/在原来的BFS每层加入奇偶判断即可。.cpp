奇数层从左到右，偶数层从右到左。
在原来的BFS每层加入奇偶判断即可。
```
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root) return res;
        q.push(root);
        bool even = false;
        while(!q.empty()){
            queue<TreeNode*> temp;
            vector<int> temp_res;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                temp_res.push_back(node->val);
                if(node->left) temp.push(node->left);
                if(node->right) temp.push(node->right);
            }
            q = temp;
            if(even){
                vector<int> reverse_t(temp_res.rbegin(), temp_res.rend());
                res.push_back(reverse_t);
                even = false;
            }else{
                res.push_back(temp_res);
                even = true;
            }
        }
        return res;
    }
};
```
