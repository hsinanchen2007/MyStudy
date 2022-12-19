### 解题思路
此处撰写解题思路
BFS
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root==NULL){
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        int temp=1,cnt=0;
        while(!q.empty()){
            TreeNode *top=q.front();
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
                v.push_back(top->val);
                temp=cnt;
                cnt=0;
            }
        }
        return v;
    }
};
```