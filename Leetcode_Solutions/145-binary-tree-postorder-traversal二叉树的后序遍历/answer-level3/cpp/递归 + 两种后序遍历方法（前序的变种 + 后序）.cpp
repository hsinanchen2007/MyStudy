### 解题思路
    誊写下来当笔记，哈哈哈 ~ ~ ~
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

/*递归*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTraversal(root,res);
        return res;
    }
    void postorderTraversal(TreeNode* root,vector<int>& res){
        if(!root) return ;
        postorderTraversal(root->left,res);
        postorderTraversal(root->right,res);
        res.push_back(root->val);
    }
};



/* 前序遍历（根->右->左）+ 反转 */
class Solution{
public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> ans;
        TreeNode* cur = root;
        stack<TreeNode*> s;
        while(cur || !s.empty()){
            while(cur){
                ans.push_back(cur->val);
                s.push(cur);
                cur = cur->right;
            }
            cur = s.top();
            s.pop();
            cur = cur->left;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


/* 直接后序遍历（需要记录pre） */
class Solution{
public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> ans;
        TreeNode* cur = root,*pre = NULL;
        stack<TreeNode*> s;
        while(cur || !s.empty()){
            while(cur){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            if(!cur->right || pre == cur->right){
                s.pop();
                ans.push_back(cur->val);
                pre = cur;
                cur = NULL;
            }else{
                cur = cur->right;
                pre = NULL;
            }
        }
        return ans;
    }
};

```