#### 由于平衡条件是，一棵树中的每个节点为根节点的树都要是平衡的，所以可以采用下面的递归思想解题。
* 第一步，确定平衡条件，对于每个节点，作如下判断
1. 当树为空，则平衡，返回true
2. 当树不空，但是左右子树为空，则平衡，返回true
3. 当树不空，且左右子树有一个为空，左右子树的高度差要小于2，否则不平衡，返回false

* 第二步，当以本节点为根的树平衡之后，还不够，对每个节点的左右子树，还要递归的运用上述条件。

* 第三步，递归的下一层返回给上一层的就是左右子树的平衡情况，左右子树有一个不平衡，则整个树不平衡。


```
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        if ((GetHeight(root->left) - GetHeight(root->right) >= 2) || (GetHeight(root->right) - GetHeight(root->left) >= 2)) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int Max(int a, int b) {
        return a > b ? a : b;
    }

    int GetHeight(TreeNode *root) {
        if (!root) return 0;
        return Max(GetHeight(root->left), GetHeight(root->right)) + 1;
    }
};
```