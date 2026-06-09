### 解题思路
此处撰写解题思路

### 代码

```cpp
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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        TreeNode* lastnode=root;
        TreeNode* newlastnode=NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            ans=0;
            TreeNode* e=q.front();
            q.pop();
            while(e!=lastnode){
                ans+=e->val;
                if(e->left){
                    q.push(e->left);
                    newlastnode=e->left;
                }
                if(e->right){
                    q.push(e->right);
                    newlastnode=e->right;
                }
                e=q.front();
                q.pop();
            }
            ans+=e->val;
            if(e->left){
                q.push(e->left);
                newlastnode=e->left;
            }
            if(e->right){
                q.push(e->right);
                newlastnode=e->right;
            }
            lastnode=newlastnode;
        }
        return ans;
    }
};
```