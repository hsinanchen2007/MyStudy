### 解题思路
1.中序遍历
2.确定边界

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
/*
方法一 中序遍历
class Solution {
public:
    bool flag = true;
    long long tmp = -DBL_MAX;
    bool isValidBST(TreeNode* root) {
        valid(root);
        return flag; 
    }
    void valid(TreeNode* root){
        if(root == NULL)return;
        valid(root->left);
        if(root->val > tmp)tmp = root->val;
        else flag = false;
        valid(root->right);
    }
};
*/
//方法二 确定边界法
class Solution{
public:
    bool isValidBST(TreeNode* root){
        return dfs(root,-DBL_MAX,DBL_MAX);
    }
    bool dfs(TreeNode* root,long long min,long long max){
        if(!root)return true;
        if(root->val < min || root->val > max)return false;
        return dfs(root->left,min,root->val-(long long)1) && dfs(root->right,root->val+(long long)1,max);
    }
};


















```