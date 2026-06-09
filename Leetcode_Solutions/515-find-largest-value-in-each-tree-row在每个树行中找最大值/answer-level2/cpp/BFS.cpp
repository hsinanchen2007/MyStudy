/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
```
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> v;
        if(root==NULL){
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        int temp=1,cnt=0,mmax=root->val;
        while(!q.empty()){
            TreeNode *top=q.front();
            if(mmax<top->val){
                mmax=top->val;
            }
            q.pop();
            if(top->left!=NULL){
                q.push(top->left);
                cnt++;
            }
            if(top->right!=NULL){
                q.push(top->right);
                cnt++;
            }
            temp--;
            if(temp==0){
                v.push_back(mmax);
                if(cnt!=0){
                    mmax=q.front()->val;
                }
                temp=cnt;
                cnt=0;
            }
        }
        return v;
    }
};
```
