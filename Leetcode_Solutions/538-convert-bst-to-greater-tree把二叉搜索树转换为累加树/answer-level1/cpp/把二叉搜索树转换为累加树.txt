
```cpp
class Solution {
public:
    int sum=0;
    //从大到小排序/遍历，每个节点加上前面所有数之和
    TreeNode* convertBST(TreeNode* root) {
        inOrder(root);
        return root;
    }
    //二叉树找树，中序遍历先遍历左子树，实现从小到大排序/遍历，先遍历右子树实现从大到小排序
    void inOrder(TreeNode*cur){
        if(!cur)return;
        inOrder(cur->right);
        sum+=cur->val;
        cur->val=sum;
        inOrder(cur->left);
    }
};
```