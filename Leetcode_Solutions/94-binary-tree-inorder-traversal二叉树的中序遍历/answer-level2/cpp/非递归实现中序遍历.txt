非递归实现中序遍历
===================

```cpp
class Solution {
public:
    //中序遍历：left->root->right
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root==NULL)return res;
        stack<TreeNode*> nodeStack;
        TreeNode* current=root;
        while(current!=NULL || !nodeStack.empty()){
            //后访问的先入栈，将不是左子叶的节点都入栈，直到第一个左子叶节入栈 
            while(current!=NULL){
                nodeStack.push(current);
                current=current->left;
            }
            //第一个左子叶节出栈
            current=nodeStack.top();
            nodeStack.pop();
            //记下左子叶的值，再开始遍历右子树
            res.push_back(current->val);
            current=current->right;
        }
        return res;
    }
};
```