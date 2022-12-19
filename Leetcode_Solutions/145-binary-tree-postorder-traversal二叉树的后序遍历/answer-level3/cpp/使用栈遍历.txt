```
class Solution {
public: 
    vector<int>res;
    stack<TreeNode *>mystack;
    TreeNode * lastvisit;//用来记录每个根节点的右侧元素是否处理过了。如果处理过了，那么当前的根节点就可以处理了。
    vector<int> postorderTraversal(TreeNode* root) {
        while(root !=NULL || !mystack .empty()){
            if(root!=NULL){
                mystack.push(root);
                root=root->left;
            }
            else{
                root=mystack.top();//访问栈顶元素
                if(root->right==NULL || root->right==lastvisit){
                    res.push_back(root->val);
                    mystack.pop();
                    lastvisit=root;
                    root=NULL;
                }
                else{
                    root=root->right;
                }
            }
        }

        return res;
    }
};
```
