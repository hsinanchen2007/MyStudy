反反复复说的，树的问题从局部思考
- 1 边界条件
- 2 已知递归函数（假设已知）如何构建当前root的解

对应本题目：
- 1 空结点符合要求`if(!root) return nullptr;`
- 特殊情况：一个单独结点的树，需要判断`root->val`与区间`[L, R]`的关系，如果在区间左边，右边，都应当抛弃。
- 2 已知`TreeNode* f(root)`能返回对一个搜索树修剪后的根
  先对root与区间做一个判断，若在区间左边，则根以及右边的子树就被扔掉（没用）, `return f(root->left)`
                          在区间右边，则根及左子树扔掉，`return f(root->right)`
                          若在区间中（意味着符合条件），则要把左右子树也怼的符合条件。


```cpp
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return nullptr;
        if(root->val < L) return trimBST(root->right, L, R);
        if(root->val > R) return trimBST(root->left, L, R);
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

```