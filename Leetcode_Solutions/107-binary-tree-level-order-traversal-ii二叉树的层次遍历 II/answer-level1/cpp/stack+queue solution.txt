和102题相比，只是把单层vector先放入stack，再输出到结果的双层vector。
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
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }

        queue<TreeNode*> que;
        que.push(root);
        int len = 1;
        stack<vector<int>> sta;

        while(que.size()){
            vector<int> pres;
            len = que.size();
            while(len){
                TreeNode* tmp = que.front();
                pres.push_back(tmp->val);
                if(tmp->left){
                    que.push(tmp->left);
                }
                if(tmp->right){
                    que.push(tmp->right);
                }
                que.pop();
                len --;
            }
            sta.push(pres);
        }

        while(sta.size()){
            result.push_back(sta.top());
            sta.pop();
        }
        return result;
    }
};
```