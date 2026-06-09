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
    vector<int> path;
    vector<int> inorderTraversal(TreeNode* root) {
        /*
        //递归
        if(root == NULL)return path;
        inorderTraversal(root->left);
        path.push_back(root->val);
        inorderTraversal(root->right);
        return path;
        */
        //迭代
        if(!root) return path;
        stack<TreeNode*> stk;
        auto p = root;
        while(p || !stk.empty()){
            while(p){
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            path.push_back(p->val);
            stk.pop();
            p = p->right;
        }
        return path;
    }
};
```