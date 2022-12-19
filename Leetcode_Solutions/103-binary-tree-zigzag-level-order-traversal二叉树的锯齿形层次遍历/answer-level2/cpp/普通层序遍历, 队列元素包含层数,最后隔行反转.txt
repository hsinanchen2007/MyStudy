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
    struct qu_node {
        TreeNode * root;
        int level;
    };
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<struct qu_node> qu;
        int level = -1;
        struct qu_node tmp;
        tmp.root = root;
        tmp.level = 0;
        qu.push(tmp);
        while(!qu.empty()){
            tmp = qu.front();
            qu.pop();
            if(tmp.level != level){
                ret.push_back(vector<int>());
                level = tmp.level;
            }
            ret[level].push_back(tmp.root->val);
            if(tmp.root->left){
                struct qu_node left;
                left.root = tmp.root->left;
                left.level = level+1;
                qu.push(left);
            }
            if(tmp.root->right){
                struct qu_node right;
                right.root = tmp.root->right;
                right.level = level+1;
                qu.push(right);                
            }
        }
        for(int i = 1; i < ret.size(); i +=2){
            reverse(ret[i].begin(), ret[i].end());
        }
        return ret;
        
    }
};
```
