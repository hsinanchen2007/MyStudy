### 解题思路
    为了训练递归，只用递归写（非递归方式可以直接打出数组，找相邻的最小差；或者用栈）
    
    idea: 左中右 遍历BST，最小差一定在相邻遍历的节点间 
    递归1： 最小值是在 （左子树，右子树，当前值和左子树最右以及右子树最左） 4者取其一
    递归2：中序遍历，当前节点减去上一个节点；用一个成员变量记录上一个节点，BST中序遍历是顺序的，后一个一定比前一个大


### 代码

```cpp
class Solution {
public:
    int md = INT_MAX;
    //训练递归
    //
    //idea: 左中右 遍历BST，最小差一定在相邻遍历的节点间 （非递归方式直接打出数组，找相邻的最小差；或者用栈）
    //递归1： 最小值是在 左子树，右子树，当前值和左子树最右以及右子树最左 4者取其一
    int minDiffInBST1(TreeNode* root) {
        if (!root) return INT_MAX;
        md = min(md, minDiffInBST(root->left));
        md = min(md, minDiffInBST(root->right));
        TreeNode* p_left = leftMost(root);
        TreeNode* p_right = rightMost(root);
        if (p_left) md = min(md, abs(root->val - p_left->val));
        if (p_right) md = min(md, abs(root->val - p_right->val));
        return md;
    }
    //递归2：中序遍历，用一个成员变量记录上一个节点，BST中序遍历是顺序的，后一个一定比前一个大
    TreeNode* ppre = nullptr;
    int minDiffInBST(TreeNode* r) {
        inorder(r);
        return md;
    }
    void inorder(TreeNode* r) {
        if (r) {
            inorder(r->left);
            if (ppre) md = min(md, r->val - ppre->val);
            ppre = r;
            inorder(r->right);
        }
    }
    TreeNode* leftMost(TreeNode* p) {
        if (!p || !p->left) return nullptr;
        p = p->left;
        while (p->right)
            p = p->right;
        return p;
    }
    TreeNode* rightMost(TreeNode* p) {
        if (!p || !p->right) return nullptr;
        p = p->right;
        while (p->left)
            p = p->left;
        return p;
    }
};
```