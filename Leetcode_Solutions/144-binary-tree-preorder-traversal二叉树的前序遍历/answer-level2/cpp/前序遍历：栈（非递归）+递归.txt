方法1： 利用栈模拟递归
```c++
vector<int> preorderTraversal(TreeNode* root) {
        //前序遍历 栈
        vector<int>vec;
        if(!root)
            return vec;
        stack<TreeNode *> stack1;
        TreeNode * curr = root;
        while(!stack1.empty() || curr)
        {
            if(curr)
            {
                vec.push_back(curr->val);
                stack1.push(curr);
                curr = curr->left;
                
            }
            else
            {
                TreeNode *pNode = stack1.top();
                stack1.pop();
                curr = pNode->right;
            }
        }
        return vec;
    }
```
方法2：直接前序遍历 +递归
```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //前序遍历 递归
        vector<int> vec;
        preorder(root,vec);
        return vec;
    }
private:
    void preorder(TreeNode *root,vector<int> &vec)
    {
        if(!root)
            return;
        vec.push_back(root->val);
        preorder(root->left,vec);
        preorder(root->right,vec);
    }
};
```