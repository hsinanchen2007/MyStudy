```
class Solution {
public:                         
     vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vi;
        stack<TreeNode*> S;
        TreeNode *p = root;
        while(p||!S.empty()){
            while(p){
                S.push(p);
                p = p->left;
            }
                p = S.top();
                S.pop();
                vi.push_back(p->val);
                p = p->right;
            }
             return vi;
        }    
};
```
1.根节点入栈
2.根节点左孩子不空，则左孩子入栈。当栈顶孩子不存在时，检查其右孩子是否存在，如果存在，则右孩子入栈
3.栈空且p指向空指针时算法结束