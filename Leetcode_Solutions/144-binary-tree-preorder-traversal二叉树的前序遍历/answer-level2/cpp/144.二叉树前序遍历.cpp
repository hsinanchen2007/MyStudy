方法一：递归方法

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
 //递归方法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraversal(root,result);
        return result;
    }
private:
    void preorderTraversal(TreeNode* root,vector<int> &result)//重载函数
    {
        if(!root)
            return ;
        result.push_back(root->val);
        preorderTraversal(root->left,result);
        preorderTraversal(root->right,result);
    }
};
```

方法二：循环方法
利用栈的先进后出，后进先出的原理
```cpp
//循环方法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> node_stack;
        if(!root)
            return {};
        node_stack.push(root);
        while(!node_stack.empty()){
            TreeNode* node=node_stack.top();
            result.push_back(node->val);
            node_stack.pop();
            if(node->right)
            {
                node_stack.push(node->right);
            }
            if(node->left)
            {
                node_stack.push(node->left);
            }
        }
        return result;
    }
}
```