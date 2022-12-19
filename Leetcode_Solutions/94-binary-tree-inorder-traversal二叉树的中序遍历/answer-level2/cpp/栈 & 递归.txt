//采用递归的方法
```
class Solution {
public:
        vector<int>res;//首先在递归函数外边创建一个全局的vector，用于下边答案的记录。
        vector<int> inorderTraversal(TreeNode* root) {
            if(root==NULL){
                return res;
            }
            if(root->left)inorderTraversal(root->left);
            res.push_back(root->val);
            if(root->right)inorderTraversal(root->right);
            return res;
        }
};
```

//用栈的方法
```
class Solution {
public:
    vector<int>res;
    stack<TreeNode *> mystack;
    vector<int> inorderTraversal(TreeNode* root) {
        while(root!=NULL || !mystack.empty()){
            if(root!=NULL){
                mystack.push(root);
                root=root->left;
            }
            else{
                root=mystack.top();//4
                mystack.pop();//pop 4
                res.push_back(root->val);//res pop4
                root=root->right;//4->right
            }
        }
        return res;
    }
};
```




//使用vector，正如前面多次表达，vector模拟stack，比直接使用stack有常数级的时间优化
```
class Solution {
public:
    vector<int>res;
    vector<TreeNode *>myvector;
    vector<int> inorderTraversal(TreeNode* root) {
        while(root!=NULL || !myvector.empty()){
            if(root!=NULL){
                myvector.push_back(root);
                root=root->left;
            }
            else{
                root=myvector.back();
                myvector.pop_back();
                res.push_back(root->val);
                root=root->right;
            }
        }
        return res;
    }
};
```

