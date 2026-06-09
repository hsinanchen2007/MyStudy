```
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;            //输出结果
        stack<TreeNode*> myStack;  //后序遍历需要用到的栈空间
        TreeNode* falg=nullptr;   //用来标志是从左孩子还是右孩子进行的回退
        while((!myStack.empty()) || root!=nullptr)
        {
            if(root!=nullptr)
            {
                myStack.push(root);
                root=root->left;
            }
            else
            {
                root=myStack.top();    //取栈顶元素，还没有出栈
                if((root->right!=nullptr)&&(root->right!=falg)) //如果右孩子存在且没有访问过，进入右孩子
                {
                    root=root->right;
                }
                else
                {
                    ans.push_back(root->val);
                    myStack.pop();
                    falg=root;
                    root=nullptr;
                }
            }
        }
        return ans;
    }
};
```
