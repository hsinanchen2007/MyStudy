# 一个简单的方法：
**1先自下而上交换左右子树。** 
**2后续遍历展开链表**

1，交换左右子树。
**交换前**
![image.png](https://pic.leetcode-cn.com/2e4b930b00c7984edefe5b23b95cf871b279b212fcd5acc5eab664410f4992c6-image.png)
**交换后**
![image.png](https://pic.leetcode-cn.com/13c4b6e494eb6b484e57e00b79756ae87a104db33fba204e5917331726fe67f5-image.png)

2,实现展开链表

![image.png](https://pic.leetcode-cn.com/26e8bcd9c021339bb169dee3520c5b2cb93a46af44d9c21a7e4021ea90136887-image.png)
```
class Solution {
public:
    void flatten(TreeNode* root) {
    if(root==NULL) return;
    swapTree(&root);
    TreeNode *lastright=root;//为记住节点最右边的节点
    while(lastright->right)lastright = lastright->right;//记住最右的一个右孩子
     helper(&root,lastright) ;
    }
    void swapTree(TreeNode **root)//交换子树
    {
        if((*root)==NULL)
            return ;
        swapTree(&(*root)->left);
        swapTree(&(*root)->right);
        swap((*root)->left,(*root)->right);
    }
    void helper(TreeNode **root,TreeNode *lastRight)//后续遍历展开链表
    {
        if(*root==NULL)
            return;
        else{
            helper(&(*root)->right,lastRight);
           
            helper(&(*root)->left,lastRight); 
             lastRight = *root;
            while(lastRight->right) lastRight = lastRight->right;//寻找节点最右边的节点
            lastRight->right = (*root)->left;
            (*root)->left =NULL;
            lastRight = lastRight->right;
        }
        
    }
};
```

