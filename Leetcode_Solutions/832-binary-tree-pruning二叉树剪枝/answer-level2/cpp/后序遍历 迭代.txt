节点可剪枝需要满足两个条件：
1. 节点值为0 
2. 节点是叶子节点

因此，需要从叶子开始剪枝，自下而上遍历整个二叉树。
满足这一需求的遍历方法是后续遍历。
遍历过程中需要寻找左侧最深叶节点，在下方代码中封装为了getLeaf函数，调用时需判断栈顶元素是否为当前节点的父节点，若不是父节点，说明栈顶元素是当前节点的兄弟，此时转移到右侧子树，需要重新寻找左侧最深叶节点。

```
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return root;
        stack<TreeNode*> S;
        TreeNode *node = root;
        S.push(root);
        while(!S.empty()){
            if(S.top()->left != node && S.top()->right != node){
                getLeaf(S);
            }
            node = S.top();
            S.pop();
            //遍历节点，判断是否剪掉子节点
            if(node->left){
                if(0 == node->left->val && NULL == node->left->left && NULL == node->left->right){
                    node->left = NULL;
                } 
            }
            if(node->right){
                if(0 == node->right->val && NULL == node->right->left && NULL == node->right->right) {
                    node->right = NULL;
                }
            }
        }
        return root;
    }

    void getLeaf(stack<TreeNode*> &S){
        while(TreeNode *x = S.top()){
            if(x->left){
                if(x->right){
                    S.push(x->right);
                }
                S.push(x->left);
            }
            else{
                S.push(x->right);
            }
        }
        S.pop();
    }

};
```
