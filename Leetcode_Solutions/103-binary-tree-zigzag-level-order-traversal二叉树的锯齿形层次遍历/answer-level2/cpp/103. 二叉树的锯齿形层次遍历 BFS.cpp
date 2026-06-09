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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        int loop = 0;
        while(!q.empty()){
            vector<int> vec_tmp;
            int q_size = q.size();
            for (int i=0; i<q_size; i++){
                TreeNode* p = q.front();
                vec_tmp.push_back(p->val);
                q.pop();

                if(p->left) {
                    q.push(p->left);
                }
                if(p->right) {
                    q.push(p->right);
                }
            }
            if (loop%2) {
                reverse(vec_tmp.begin(), vec_tmp.end()); /*比第102题多了这里的隔行反转*/
            }
            loop++;
            res.push_back(vec_tmp);
        }

        return res;
    }
};
```
