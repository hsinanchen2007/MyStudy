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
    vector<int> inorderTraversal(TreeNode* root) {
        //传的参数是树，指针类型；
        vector<int> res;//输出为值的中序遍历
        midfor(res,root);
        return res;
    }
    void midfor(vector<int> &res,TreeNode *root){
        while(root){
            if(root->left!=NULL) midfor(res,root->left);
            res.push_back(root->val);
            if(root->right!=NULL) midfor(res,root->right);
            return;
        }
    }
};
```