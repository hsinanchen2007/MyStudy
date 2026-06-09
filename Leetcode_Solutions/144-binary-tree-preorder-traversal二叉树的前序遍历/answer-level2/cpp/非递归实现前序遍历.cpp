非递归实现前序遍历
=================

```cpp

class Solution {
public:
    //非递归实现前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)return res;
        stack<TreeNode*> nodeStack;
        //使用栈
        nodeStack.push(root);
        
        TreeNode* current;
        //直到栈为空，全部访问结束
        while(!nodeStack.empty()){
            //弹出节点后，子节点入栈
            current=nodeStack.top();
            nodeStack.pop();
            //访问当前节点
            res.push_back(current->val);
            //前序遍历访问完根节点先访问左，所以先让右节点入栈
            if(current->right)nodeStack.push(current->right);
            if(current->left)nodeStack.push(current->left);
        }
        return res;
    }
};
```