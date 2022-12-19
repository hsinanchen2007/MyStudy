该题目要求原地，且输出看起来很像先序遍历的结果，于是：
一个非常简单的思路，将每个节点的右子树挂到左节点的先序遍历最后一点的右下角
如果只有左子树，就把这个左子树变成父节点的右子树
其余情况无操作
```
void flatten(TreeNode* root) {
        TreeNode* p;
        while(root){
            if(root->right&&root->left){//左右子树都有
            p=root->left;
            while(p->right) p=p->right;
            p->right=root->right;//右子树变成左子树先序遍历最后一点的右子树
            root->right=root->left;//父节点的左子树变成右子树
            root->left=NULL;//左子树清空
        }
        else if(!root->right) {//只有左子树
            root->right=root->left;//左子树变成父节点的右子树
            root->left=NULL;//左子树清空
        }   
        else;
        root=root->right;//找到下一个需要处理的父节点
        }
    }
```
