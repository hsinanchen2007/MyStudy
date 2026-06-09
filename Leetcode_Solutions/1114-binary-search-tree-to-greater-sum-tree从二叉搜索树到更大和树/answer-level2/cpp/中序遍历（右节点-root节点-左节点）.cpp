根据二叉搜索树的约束条件，从最右节点开始中序遍历，节点的值叠加下去。

C++代码:

```
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        infixOrder(root);
        return root;
    }
    void infixOrder (TreeNode* root)
    {
        if(root != NULL)
        {
            infixOrder(root->right);
            int temp = root->val;
            root->val += _sum;
            _sum += temp;
            infixOrder(root->left);
        }
    }
private:
    int _sum = 0;
};
```
