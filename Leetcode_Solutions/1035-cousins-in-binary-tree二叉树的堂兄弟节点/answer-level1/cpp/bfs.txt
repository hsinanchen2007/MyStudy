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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)return false;
        queue<TreeNode*> q;
        q.push(root);
        int xx=-1,yy=-1;
        int level=0;
        TreeNode *last=root;
        TreeNode* newlast=root;
        while(!q.empty()){
            TreeNode* e=q.front();
            q.pop();
            if(e->val==x)xx=level;
            if(e->val==y)yy=level;
            if(e->left&&e->right){
                if(e->left->val==x&&e->right->val==y)return false;
                if(e->left->val==y&&e->right->val==x)return false;
            }
            if(e->left){
                q.push(e->left);
                newlast=e->left;
            }
            if(e->right){
                q.push(e->right);
                newlast=e->right;
            }
            if(last==e){
                last=newlast;
                level++;
            }
            if(xx!=-1&&yy!=-1){
                break;
            }
        }
        return xx==yy? true:false;
    }
};
```