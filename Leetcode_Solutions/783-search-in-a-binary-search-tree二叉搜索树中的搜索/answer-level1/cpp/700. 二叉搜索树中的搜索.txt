递归法：
```
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root->val == val) return root;
        if(root->left != NULL && val < root->val) return searchBST(root->left, val);
        if(root->right != NULL && val > root->val) return searchBST(root->right, val);
        return NULL;
    }
};
```



迭代法：
```
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode * Node = root;
        while(Node != NULL && Node->val != val)
            Node = Node->val < val ? Node->right : Node->left;
        return Node;
    }
};
```
