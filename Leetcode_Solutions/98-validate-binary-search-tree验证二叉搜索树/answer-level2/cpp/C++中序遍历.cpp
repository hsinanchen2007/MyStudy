用时比较多，但是思路很清晰。
利用二叉排序树中序遍历有序来解决。
```c++
class Solution {
public:
    long last = LONG_MIN; // 父节点值
    bool flag = true; // 父亲结点是否大于子节点
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        // 遍历左子树
        if(flag && root->left)
            isValidBST(root->left);
        
        // 当前结点不大于父节点，不是排序二叉树
        if(root->val <= last)
            flag = false;
        
        last = root->val; // 记录父节点值
        
        // 遍历右子树
        if(flag && root->right)
            isValidBST(root->right);
        
        // 子树都遍历完 或 不是二叉排序树，就退出
        return flag;
    }
};
```