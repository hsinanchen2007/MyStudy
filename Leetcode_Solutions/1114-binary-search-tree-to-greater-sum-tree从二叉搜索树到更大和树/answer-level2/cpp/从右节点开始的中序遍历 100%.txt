从右节点开始的中序遍历

```

class Solution {
public:
    void gather(TreeNode *root, int &sum) {
        if (!root) 
            return;
        gather(root->right, sum);
        root->val += sum;
        sum = root->val;
        gather(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        gather(root, sum);
        return root;
    }
};
```
