这道题与[94 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)类似。
```
class BSTIterator {
    stack<TreeNode*> nodes;
    void prepare(TreeNode *root){
        for(; root; root=root->left)
            nodes.push(root);
    }
public:
    BSTIterator(TreeNode* root) {
        for(; nodes.size(); nodes.pop());
        prepare(root);
    }
    
    /** @return the next smallest number */
    int next() {
        if(nodes.size()==0) return 0;
        TreeNode *node=nodes.top();
        nodes.pop();
        prepare(node->right);
        return node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return nodes.size();
    }
};
```
