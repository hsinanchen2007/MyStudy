### 解题思路
递归法
非递归y

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
//递归
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return ans;
        if(root->left) inorderTraversal(root->left);
        ans.push_back(root->val);
        if(root->right) inorderTraversal(root->right);
        return ans;
    }
};
//非递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(cur||!s.empty()){
            if(cur){
                s.push(cur);
                cur=cur->left;
            }
            else {
                cur=s.top();
                s.pop();
                ans.push_back(cur->val);
                cur=cur->right;
            }
        }
        return ans;
    }
};
```