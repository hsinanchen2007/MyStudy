```cpp
public:
    TreeNode* updown(TreeNode* node)
    {
        if(!node)
        return NULL;
        TreeNode* Mright=updown(node->right);
        TreeNode* Mleft=updown(node->left);
        TreeNode* node1=Mleft;
        node->left=Mright;
        node->right=node1;
        return node;
    }
    TreeNode* invertTree(TreeNode* root) {
        updown(root);
        return root;
    }
};
```