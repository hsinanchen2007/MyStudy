1.首先看此节点是否有右孩子，有则返回以有孩子为根节点的子树中最左侧节点
2.此时此节点应该没有右孩子，找到root到p的路径，存在stack中（stack中的节点均为p祖先）
3.从p开始逆向向root回退，如果当前p是父节点的右孩子，继续回退，否则当前p是父节点的左孩子，直接返回父节点
4.如果没找到返回NULL
```
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(NULL == root || NULL == p) return NULL;
        TreeNode* node = p->right;
        while(node && node->left)
            node = node->left;
        if(node) return node;
        
        node = root;
        stack<TreeNode*> s;
        while(node != p){
            s.push(node);
            if(node->val > p->val)
                node = node->left;
            else
                node = node->right;
        }
        
        TreeNode* child  = p;
        TreeNode* parent = NULL;
        while(!s.empty()){
            parent = s.top();
            s.pop();
            if(parent->left == child)
                return parent;
            child = parent;
        }
        return NULL;
    }
};
```
