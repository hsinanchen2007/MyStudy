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
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *mark=new TreeNode(0);
        q.push(mark);
        while(q.size()>1){
            TreeNode* tp=q.front();
            if(!tp->val){
                q.pop();
                q.push(mark);
                ans=0;
                continue;
            }
            ans+=tp->val;
            if(tp->left)q.push(tp->left);
            if(tp->right)q.push(tp->right);
            q.pop();
        }
        return ans;
    }
};
```