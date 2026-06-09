按以下规则处理节点：
1. d == 1，新建节点并将root作为左子树，直接返回新节点
2. d == 2，新建左右子树节点，并将原左右子树分别作为新左右节点的左右子节点
3. d > 3，递归处理非空左右子树，并将d减1

```
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1) {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        if(d==2) {
            TreeNode* lnode = new TreeNode(v);
            lnode->left = root->left;
            root->left = lnode;
            TreeNode* rnode = new TreeNode(v);
            rnode->right = root->right;
            root->right = rnode;
            return root;
        }
        if(root->left) addOneRow(root->left, v, d-1);
        if(root->right) addOneRow(root->right, v, d-1);
        return root;
    }
};
```
