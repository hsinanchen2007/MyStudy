先对二叉树进行中序遍历，然后我们得到了有序序列（从小到大排列）

之后我们对序列进行处理，让每一个值都变为大于等于它的值之和。
我们只需要从后往前累加即可。

接下来，进行中序遍历，再将数据重新赋值给节点。

代码:
```
class Solution {
public:
    vector<int>res;
    void dfs(TreeNode* root){
        if(root->left){
            dfs(root->left);
        }
        res.push_back(root->val);
        if(root->right){
            dfs(root->right);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        dfs(root);
        for(int i=res.size()-2;i>=0;i--){
            res[i]+=res[i+1];
        }
        TreeNode* ans=root;
        int idx=0;
        stack<TreeNode*>myStack;
        while(root||!myStack.empty()){
            while(root){
                myStack.push(root);
                root=root->left;
            }
            root=myStack.top();
            myStack.pop();
            root->val=res[idx++];
            root=root->right;
        }
        return ans;
    }
};
```
