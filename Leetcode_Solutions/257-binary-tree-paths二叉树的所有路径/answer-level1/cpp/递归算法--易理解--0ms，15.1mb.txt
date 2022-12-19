### 解题思路
大致思路就是递归的先序遍历（DFS），每经过一个节点就记录，递归工作栈之间传输的是字符串，每次加上左右节点的值然在再在左右节点转发，当达到叶结点时添加此字符串

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL) return ans;
        helper(ans, to_string(root->val), root);
        return ans;
    }
    //先序遍历
    void helper(vector<string>& ans, string str, TreeNode* root) {
        //两者都是空的话，则是叶结点
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(str);
            return;
        }
        if(root->left != NULL) helper(ans, str + "->" + to_string(root->left->val), root->left);
        if(root->right != NULL) helper(ans, str + "->" + to_string(root->right->val), root->right);
    
    }

};
```