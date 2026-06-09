```C++
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0|| inorder.size() == 0)
            return nullptr;
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir){
        if(pl > pr || il > ir)
            return nullptr;
        // 1. 创建root
        TreeNode* root = new TreeNode(preorder[pl]);
        // 2. 在中序遍历中找到root节点, root左边是左子树,右边是右子树
        int root_pos = 0;
        while(root_pos < inorder.size()){
            if(inorder[root_pos] == root->val)
                break;
            root_pos++;
        }
        int lt = root_pos - il;     //左子树节点的个数
        int rt = ir - root_pos;     //右子树节点的个数
        // 3.递归构建左右子树
        root->left = helper(preorder, pl + 1, pl + lt, inorder, il, il + lt - 1);
        root->right = helper(preorder, pl + lt + 1, pr, inorder, il+lt+1, ir);
        return root;

    }
};
```