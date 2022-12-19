### 解题思路
首先dfs,然后在回溯的时候将每一个节点的val更改为其高度，并同时将答案更新
简洁的主函数（逃

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
    int ans = 0;
    void dfs(TreeNode* p){
        if(p==NULL)return;
        else if(p->left==NULL&&p->right==NULL)p->val = 1;
        else
        {
            dfs(p->left);
            dfs(p->right);
            if(p->left==NULL&&p->right==NULL)
            {
                p->val = 1;
            }
            else if(p->left==NULL){
                p->val = p->right->val+1;
                ans = max(ans,p->right->val);
            }
            else if(p->right==NULL){
                p->val = p->left->val+1;
                ans = max(ans,p->left->val);
            }
            else{
                p->val = max(p->left->val,p->right->val)+1;
                ans = max(ans,p->left->val+p->right->val);

            }


        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;


    }
};
```